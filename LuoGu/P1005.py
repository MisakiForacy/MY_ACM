n,m=map(int,input().split())
for i in range(n+1):
    for j in range(m+1):
        cnt=-1
        for ii in range(n+1):
            for jj in range(m+1):
                y3=(j+jj)/2+(i-ii)/2
                y4=(j+jj)/2-(i-ii)/2
                x3=(i+ii)/2+(j-jj)/2
                x4 = (i + ii) / 2 -(j - jj) / 2
                if( x3%1==0 and x4%1==0  and y3%1==0 and y4%1==0 and 0<=y3<=m and 0<=y4<=m and 0<=x3<=n and 0<=x4<=n):
                    cnt+=1
        print(cnt,end=' ')
    print()