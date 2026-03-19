cnt = 0
n,k = map(int,input().split())
mp = {1:0,2:0,3:0,4:0,5:0,6:0}
for i in range(1,n+1):
    print(i,int(i**(1/k)),i % int(i**(1/k))==0)
    if i % int(i**(1/k))==0:
        cnt += 1
        mp[int(i**(1/k))] += 1
        
print(mp)
print(cnt)