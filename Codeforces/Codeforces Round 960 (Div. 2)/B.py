t=int(input())
for i in range(t):
    n,x,y=map(int,input().split())
    a=list(1 for i in range(n+2))
    a[x+1]=-1
    a[y-1]=-1
    for j in range(x+2, n + 2,2):
        a[j]=-1
    for j in range(0, y-1,2):
        a[j]=-1
    for j in range(1,n+1):
        print(a[j],end=" ")
    print()