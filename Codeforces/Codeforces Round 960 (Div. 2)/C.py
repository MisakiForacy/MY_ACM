t=int(input())
for i in range(t):
    s=0
    mx=0
    n=int(input())
    a=list(map(int,input().split()))
    #b=[-1 for i in range(n+1)]

    for j in range(n):
        s += sum(a)
        mx=0
        b = [-1 for i in range(n + 1)]
        for i in range(j,n):
            b[a[i]]+=1
            if(b[a[i]]==1):
                if(b[a[i]]>mx):
                    mx=a[i]
            a[i]=mx
        #print(a)
    print(s)