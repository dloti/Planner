#include <planning/FF_PDDL_To_STRIPS.hxx>
#include <planning/STRIPS_Problem.hxx>
#include <planning/Fluent.hxx>
#include <planning/Action.hxx>
#include <planning/PDDL_Type.hxx>
#include <planning/PDDL_Object.hxx>
#include <planning/PDDL_Operator.hxx>
#include <planning/heuristics/Max_Heuristic.hxx>
#include <planning/heuristics/Relaxed_Plan_Extractor.hxx>
#include <planning/Types.hxx>
#include <planning/inference/Propagator.hxx>

#include <search/Node.hxx>
#include <search/Best_First_Search.hxx>

#include <util/time.hxx>
#include <util/ext_math.hxx>

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <cmath>

using namespace std;
map<string, int> concepts;
map<string, int> significantObjectIdx;
vector<string> actions;
aig_tk::PDDL_Object_Ptr_Vec allObjects;
vector<aig_tk::Fluent_Vec> stateFluents;

void get_plan(aig_tk::STRIPS_Problem& strips_prob, vector<aig_tk::Node*>& plan) {
	aig_tk::Max_Heuristic estimator;
	estimator.initialize(strips_prob);
	estimator.compute(strips_prob.init());
	aig_tk::Cost_Type goal_cost = estimator.eval(strips_prob.goal());

	aig_tk::Node* n0 = aig_tk::Node::root(strips_prob);
	/**
	 * SEARCH
	 **/

	aig_tk::Best_First_Search engine;

	engine.set_heuristic(estimator);
	engine.set_problem(strips_prob);

	//float t0, tf;

	//t0 = time_used();

	//	if (engine.solve(n0, plan)) {
	//		tf = time_used();
	//		//output_plan(plan, t0, tf);
	//	}

	plan.clear();
	n0 = aig_tk::Node::root(strips_prob);
	stateFluents.clear();
	stateFluents.push_back(n0->s()->fluent_vec());
	if (engine.solve(n0, plan)) {
		//tf = time_used();
		//output_plan(plan, t0, tf);
		for (unsigned i = 0; i < plan.size(); i++)
			stateFluents.push_back(plan[i]->s()->fluent_vec());
	} else
		std::cerr << "FALLO" << std::endl;

}

void get_state(aig_tk::STRIPS_Problem& prob, int state, ostream& out) {

	int tmp = 0;
	string current_predicate;
	cout << "State: " << state << endl;
	map<string, int>::iterator itr;
	for (itr = concepts.begin(); itr != concepts.end(); ++itr) {
		if (itr->second == 1) {
			out << itr->first << "\t";
			cout << itr->first << "\t";
			for (unsigned i = 0; i < stateFluents[state].size(); i++) {
				tmp = stateFluents[state][i];

				aig_tk::Index_Vec types_idxs = prob.fluents()[tmp]->pddl_types_idx();
				int arity = types_idxs.size();
				current_predicate = prob.fluents()[tmp]->predicate();

				if (current_predicate.compare(itr->first) != 0
						|| (prob.types()[types_idxs[0]]->name().compare("NO-TYPE")) == 0 || arity > 2)
					continue;

				aig_tk::Index_Vec& objs_idx = prob.fluents()[tmp]->pddl_objs_idx();

				for (unsigned j = 0; j < objs_idx.size(); j++) {
					out << allObjects[objs_idx[j]]->signature() << " ";
					cout << allObjects[objs_idx[j]]->signature() << " ";
				}
			}
			out << endl;
			cout << endl;
		}
	}
	//For roles
	for (itr = concepts.begin(); itr != concepts.end(); ++itr) {
		if (itr->second == 2) {
			out << itr->first << "\t";
			cout << itr->first << "\t";
			for (unsigned i = 0; i < stateFluents[state].size(); i++) {
				tmp = stateFluents[state][i];

				aig_tk::Index_Vec types_idxs = prob.fluents()[tmp]->pddl_types_idx();
				int arity = types_idxs.size();
				current_predicate = prob.fluents()[tmp]->predicate();

				if (current_predicate.compare(itr->first) != 0
						|| (prob.types()[types_idxs[0]]->name().compare("NO-TYPE")) == 0 || arity != 2)
					continue;

				aig_tk::Index_Vec& objs_idx = prob.fluents()[tmp]->pddl_objs_idx();

				if (arity == 2 && objs_idx.size() == 2) {
					cout << "(" << allObjects[objs_idx[0]]->signature() << "," << allObjects[objs_idx[1]]->signature()
							<< ") ";
					out << allObjects[objs_idx[0]]->signature() << "," << allObjects[objs_idx[1]]->signature() << " ";
				}
			}

			out << endl;
			cout << endl;
		}
	}

}

void get_primitive_concepts(aig_tk::STRIPS_Problem& prob, ostream& out) {
	//Get types as primitive concepts
	for (unsigned i = 0; i < prob.num_types(); i++) {
		string type_signature = prob.types()[i]->signature();
		if (type_signature.compare("NO-TYPE") == 0 || type_signature.compare("ARTFICIAL-ALL-OBJECTS") == 0)
			continue;
		out << type_signature << "\t";
	}

	//Get fluents as primitive concepts
	aig_tk::Index_Vec types_idxs;
	unsigned fnum = prob.num_fluents();

	for (unsigned k = 0; k < fnum; k++) {
		types_idxs = prob.fluents()[k]->pddl_types_idx();

		if (types_idxs.size() == 1 && prob.types()[types_idxs[0]]->name() == "NO-TYPE") {
			continue;
		}

		concepts[prob.fluents()[k]->predicate()] = types_idxs.size();
	}
	map<string, int>::iterator itr;
	for (itr = concepts.begin(); itr != concepts.end(); ++itr)
		if (itr->second == 1)
			out << itr->first << "\t";
	out << endl;
	for (itr = concepts.begin(); itr != concepts.end(); ++itr)
		if (itr->second == 2)
			out << itr->first << "\t";
	out << endl;
}

void get_instance_objects(aig_tk::STRIPS_Problem& prob, ostream& out) {
	allObjects.clear();
	allObjects = prob.objects();
	aig_tk::PDDL_Object_Ptr_Vec::iterator itr;
	for (itr = allObjects.begin(); itr != allObjects.end(); ++itr) {
		if ((*itr)->signature().compare("NO-OBJECT") == 0)
			continue;

		out << (*itr)->signature() << "\t";
	}
	out << endl;
}

void get_actions(aig_tk::STRIPS_Problem& prob, ostream& out) {
	aig_tk::Action_Ptr_Vec probActions = prob.actions();
	for (unsigned i = 0; i < probActions.size(); ++i) {
		if (find(actions.begin(), actions.end(), probActions[i]->name()) == actions.end()
				&& !probActions[i]->name().empty())
			actions.push_back(probActions[i]->name());
	}
	for (unsigned i = 0; i < actions.size(); ++i)
		out << actions[i] << "\t";
}

int main(int argc, char** argv) {
	if (argc < 3) {
		std::cerr << "No prob description provided, bailing out!" << std::endl;
		std::exit(1);
	}
	std::string folder(argv[1]);
	int instance_num(atoi(argv[2]));
	cout << folder << " " << instance_num << endl;
	string instance("instance");
	ofstream fout, dout, nappout;

	ifstream fin("aux_domain.txt");
	string line;
	while (!fin.eof() && getline(fin, line)) {
				istringstream iss(line);

				string tmp;
				int action_num = -1;
				getline(fin, tmp);
				std::istringstream(tmp) >> action_num;
				significantObjectIdx[line] = action_num;
	}

	dout.open("domain.txt");
	fout.open("plans.txt", ios::app);
	nappout.open("non_applicable.txt", ios::app);
	string instance_path;
	folder = "./problems/" + folder + "/";
	string domain = folder + "domain.pddl";
	std::vector<aig_tk::Node*>* plan;
	aig_tk::STRIPS_Problem* strips_prob;

	int exampleNum = 0;
	instance_path = folder + instance + static_cast<ostringstream*>(&(ostringstream() << instance_num))->str()
			+ ".pddl";

	strips_prob = new aig_tk::STRIPS_Problem();
	aig_tk::FF_PDDL_To_STRIPS adl_compiler = aig_tk::FF_PDDL_To_STRIPS();
	adl_compiler.get_problem_description(domain, instance_path, *strips_prob, true);
	cout << "Compiled" << endl;

	plan = new vector<aig_tk::Node*>();
	get_plan(*strips_prob, *plan);
	get_primitive_concepts(*strips_prob, dout);
	get_instance_objects(*strips_prob, dout);
	get_actions(*strips_prob, dout);

	fout << instance_num << "\t" << plan->size() << endl;
	get_state(*strips_prob, 0, fout);


	aig_tk::Node* n = aig_tk::Node::root(*strips_prob);
	for (unsigned i = 0; i < plan->size(); i++) {
		exampleNum++;

		fout << (*plan)[i]->op()->name();
		nappout<<exampleNum-1<<endl;

		map<string,vector<int> > applicableActions;
		for(unsigned j = 0; j < strips_prob->num_actions(); j++) {
			 aig_tk::Action* a = strips_prob->actions()[j];
			 if( a->can_be_applied_on(*(n->s())) ) {
				 aig_tk::Index_Vec objs_idx = a->pddl_objs_idx();
				 string aname = a->name();
				 int sigObjIdx = significantObjectIdx[aname];
				 if(sigObjIdx == -1 &&  applicableActions[aname].size() == 0){
					 applicableActions[aname].push_back(-1);
					 continue;
				 }
				 if(find(applicableActions[aname].begin(),applicableActions[aname].end(),objs_idx[sigObjIdx] )
						 ==applicableActions[aname].end()){
					 applicableActions[aname].push_back(objs_idx[sigObjIdx]);
				 }
			 }
		}
		map<string,vector<int> > printedActions;

	    for(unsigned j = 0; j < strips_prob->num_actions(); j++) {
	    	    aig_tk::Action* a = strips_prob->actions()[j];

	            if((*plan)[i]->op()->name().compare(a->name())==0){
	            	if( !a->can_be_applied_on(*(n->s())) ) {
	            		aig_tk::Index_Vec objs_idx = a->pddl_objs_idx();
	            		string aname = a->name();
	            		if(aname.compare("")==0) continue;
	            		int sigObjIdx = significantObjectIdx[aname];
	            		int sigObj = -1;
	            		if(sigObjIdx != -1 ) sigObj = objs_idx[sigObjIdx];

	            		 if(find(applicableActions[aname].begin(),applicableActions[aname].end(),sigObj)
	            			            								 !=applicableActions[aname].end()){
	            			 continue;
	            		 }
	            		 if(find(printedActions[aname].begin(),printedActions[aname].end(),sigObj )
	            		 	            			            			!=printedActions[aname].end()){
	            		 	            			 continue;
	            		 }

	            		 nappout<<aname;
	            		 if(sigObj != -1){
	            			 int sigObjIdx = significantObjectIdx[aname];
	            			 nappout << " " << allObjects[sigObj]->signature();
	            			 printedActions[aname].push_back(sigObj);
	            		 }else{
	            			 if(sigObj == -1 &&  printedActions[aname].size() == 0){
	            				 printedActions[aname].push_back(-1);
	            			 }
	            		 }
	            		 nappout << endl;
	            	 }
	            }
	    }
	    nappout<<endl;

	    aig_tk::Index_Vec objs_idx = (*plan)[i]->op()->pddl_objs_idx();
		for (unsigned j = 0; j < objs_idx.size(); ++j)
			fout << " " << allObjects[objs_idx[j]]->signature();
		fout << endl;
		get_state(*strips_prob, i + 1, fout);

		n = n->successor((*plan)[i]->op());
	}

	std::cout << std::endl;
	std::cout << "Actions: " << strips_prob->num_actions();
	std::cout << " Fluents: " << strips_prob->num_fluents() << std::endl;
	delete strips_prob;
	delete plan;

	cout << "Examples: " << exampleNum << endl;
	fout.flush();
	fout.close();
	dout.flush();
	dout.close();
	return 0;
}

