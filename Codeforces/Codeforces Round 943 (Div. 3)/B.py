t = int(input())
for _ in range(t):
    cnt = 0
    l = 0
    flag = True
    n,m = map(int,input().split())
    a = input()
    b = input()
    for i in range(n):
        if a[i] in b[l:]:
            l = b[l:].index(a[i])+1
        else:
            flag = False
            print(i-1)
            break
    if flag:
        print(i)