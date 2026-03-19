t=int(input())                                    
for i in range(t):
    n,m=map(int,input().split())
    c=list(list(input().strip())for _ in range(n))    
    d=c[0][0]
    f=0
    ff=0                                              
    fff=0
    ffff=0
    if(c[0][0]==c[n-1][m-1] or c[0][m-1]==c[n-1][0]):
        print("YES")
    else:
        for j in range(1,n):                                  
            if c[j][0]!=d:                                        
                f=1                                               
                break
        for j in range(1,m):
            if c[0][j]!=d:
                ff=1
                break
        for j in range(0,n-1):
            if c[j][m-1]!=c[n-1][m-1]:
                fff=1
                break                                     
        for j in range(0,m-1):
            if c[n-1][j]!=c[n-1][m-1]:
                ffff=1
                break
        if((f and ff) or (fff and ffff)):
            print("YES")
        else:
            print("NO")