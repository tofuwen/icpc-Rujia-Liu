import math
import sys

# sys.stdin.close()
# sys.stdin = open("data.txt", "r")

while(True):
    s = input()
    a, b = map(int, s.split())
    if(a == 0):
        break
    m = math.ceil(math.sqrt(a-0.5))
    M = math.floor(math.sqrt(b+0.5))
    print(M-m+1)
