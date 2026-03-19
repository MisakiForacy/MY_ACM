from queue import Queue
n,m=map(int,input().split())
tu=[list(input().strip()) for i in range(n)]
a=[list('#' for i in range(m)) for j in range(n)]
fx=[[0,1],[0,-1],[1,0],[-1,0]]
def dfs1(x,y):
    tu[x][y]='#' 
    for i in range(4):
        x1=fx[i][0]+x
        y1=fx[i][1]+y
        if 0<=x1<n and 0<=y1<m and tu[x1][y1]=='.':
            a[x1][y1]='1'
            dfs1(x1,y1)
            
def dfs2(x,y):
    tu[x][y]='#' 
    for i in range(4):
        x1=fx[i][0]+x
        y1=fx[i][1]+y
        if 0<=x1<n and 0<=y1<m and tu[x1][y1]=='.':
            a[x1][y1]='2'
            dfs2(x1,y1)
            
def dffs(x,y):
    global f #定义全局变量
    a[x][y]='.' 
    for i in range(4):
        x1=fx[i][0]+x
        y1=fx[i][1]+y
        if 0<=x1<n and 0<=y1<m:
            if a[x1][y1]=='1':
                dffs(x1,y1)
            elif a[x1][y1]=='#':    
                while(0<=x1<n and 0<=y1<m):
                    x1=fx[i][0]+x1
                    y1=fx[i][1]+y1
                    print(x1,y1,i)
                    for j in range(4):
                        xx1=fx[j][0]+x1
                        yy1=fx[j][1]+y1
                        if(0<=xx1<n and 0<=yy1<m and a[xx1][yy1]=='2'):
                            f=1
                            #return
            elif(a[x1][y1]=='2'):
                f=1
                return
                    
            
for i in range(n):
    for j in range(m):
        if(tu[i][j]=='S'):
            dfs1(i,j)
            xx=i;yy=j
        if(tu[i][j]=='E'):
            a[i][j]='2'
            dfs2(i,j)
            
print(a)
f=0
dffs(xx,yy)
if(f):
    print("YES")
else:
    print("NO")