import sys

#sys.stdin.close()
#sys.stdin = open("data.txt", "r")

T = int(input())

for cc in range(T):
    s = input()
    num = [0, 0, 0]
    for c in s:
        num[int(c) % 3] = num[int(c) % 3] + 1
    total = (num[1] + 2 * num[2]) % 3
    if(total != 0):
        if(num[total] > 0):
            ok = (num[0] % 2) ^ 1
        else:
            ok = 0
    else:
        ok = num[0] % 2
    if ok == 1:
        s = "Case "+str(cc+1)+": S"
        print(s)
    else:
        t = "Case "+str(cc+1)+": T"
        print(t)
