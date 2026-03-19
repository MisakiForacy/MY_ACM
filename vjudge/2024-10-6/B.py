n = int(input())
num = list(map(int,input().split()))
tot = 0
for i in range(n):
    tot = tot + 2**i*num[i]
    if tot > 0:
        print("+",end="")
    elif tot == 0:
        print("0",end="")
    else:
        print("-",end="")
    # tot /= 2