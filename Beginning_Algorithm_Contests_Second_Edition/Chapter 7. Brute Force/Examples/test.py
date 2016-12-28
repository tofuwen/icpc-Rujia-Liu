import sys
import random

sys.stdout = open("data.txt", "w")

test_case = 10
print test_case

for i in range(test_case):
	s = random.randint(1, 6)
	print random.uniform(1, 6)
	print s
	for j in range(s):
		print random.randint(1, 100)
