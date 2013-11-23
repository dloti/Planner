import subprocess
import shutil
import sys

open('plans.txt', 'w').close()
open('non_applicable.txt', 'w').close()
instances_num = int(sys.argv[2])
for i in range(1,instances_num+1):
	subprocess.call(["./planner", str(sys.argv[1]), str(i)])


shutil.copy2('plans.txt', '../Student/plans.txt')
shutil.copy2('non_applicable.txt', '../Student/non_applicable.txt')

