import sys
import math

# sys.stdin.close()
# sys.stdin = open("data.txt", "r")

T = int(input())


def lcm(a, b):
    return a//math.gcd(a, b)*b

for cc in range(T):
    s = input()
    a, c = map(int, s.split())
    # print(sys.getsizeof(1))
    if c % a == 0:
        ans = c//a
        cur = lcm(ans, a)
        while(cur != c):
            ans = ans * (c // cur)
            cur = lcm(ans, a)
        print(ans)
    else:
        print("NO SOLUTION")
