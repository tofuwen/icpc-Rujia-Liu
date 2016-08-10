import numpy.random as nr
import sys

sys.stdout.close()
sys.stdout = open("data.txt", "w")

T = 10
print(T)

for cc in range(T):
    for i in range(2):
        a = nr.randint(360, 1080)
        b = nr.randint(360, 1080)
        while b == a:
            a = nr.randint(360, 1080)
            b = nr.randint(360, 1080)
        print(min(a, b), max(a, b), end=' ')
    print(nr.randint(1, 91))
