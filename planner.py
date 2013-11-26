import subprocess
import shutil
import sys

open('plans.txt', 'w').close()
instances_num = int(sys.argv[2])
for i in range(1,instances_num+1):
	subprocess.call(["./planner", str(sys.argv[1]), str(i)])

shutil.copy2('domain.txt', '../PlanValidator/domain.txt')
shutil.copy2('plans.txt', '../PlanValidator/plans.txt')
shutil.copy2('plans.txt', '../Student/plans.txt')

print "--- Training set validation --"
for i in range(1,instances_num+1):
	child = subprocess.call(["../PlanValidator/validator", str(sys.argv[1]), str(i)])
	if child != 0:
		print "ERR PLANS not valid!"
		break
		
print "Training set valid"
