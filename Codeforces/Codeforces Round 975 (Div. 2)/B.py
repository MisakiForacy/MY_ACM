t=int(input())
for _ in range(t):
    n,qq=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int, input().split()))
    c={}
    p=0
    q=n
    for i in range(1,n):
        if(i!=1):
            if((i)*(n-i) in c):
                try:
                    c[(i)*(n-i)]+=a[i]-a[i-1]-1
                except:
                    c.update[{(i)*(n-i),a[i]-a[i-1]-1}]
            else:
                try:
                    c[(i) * (n - i)] = a[i] - a[i - 1] - 1
                except:
                    c.update({i*(n-i),a[i]-a[i-1]-1})
        q-=1
        p=q+(q+1)*(i-1)
        if(p in c):
            c[p]+=1
        else:
            c[p]=1
    c[n-1]=c[n-1]+1+a[1]-a[0]-1
    for i in range(qq):
        if(b[i]in c):
            print(c[b[i]],end=' ')
        else:
            print(0,end=' ')
    print()
    # print(c)
    # print(b)
