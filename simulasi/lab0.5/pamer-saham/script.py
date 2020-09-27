import sys
import os
import glob

cnt = 0
os.system("tcframe build")
os.system("./runner")
os.system("rm -rf tc/input")
os.system("mkdir tc/input")
for x in sorted(glob.glob("tc/*.in")):
	newFileName = "tc/input/input%02d.txt" % (cnt)
	command = "mv %s %s" % (x, newFileName)
	os.system(command)
	cnt += 1

cnt = 0
os.system("rm -rf tc/output")
os.system("mkdir tc/output")
for x in sorted(glob.glob("tc/*.out")):
	newFileName = "tc/output/output%02d.txt" % (cnt)
	command = "mv %s %s" % (x, newFileName)
	os.system(command)
	cnt += 1
