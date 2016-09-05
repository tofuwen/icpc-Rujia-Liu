import sys
import random

sys.stdout.close()
sys.stdout = open("data.txt", "w")

test_cases = 10

for i in range(test_cases):
    n = random.randint(1, 1000)
    print(n)
    for j in range(n):
        print(random.randint(1, 1000))

print(0)
