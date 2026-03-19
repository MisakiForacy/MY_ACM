import math
n = int(input())
l,r = map(int,input().split())
ans = 0
for num in range(l,r+1):
    idx = int(n/2)
    n1 = int(str(num)[:idx])
    n2 = int(str(num)[idx:])
    # print(n1,n2)
    if math.sqrt(n1)==int(math.sqrt(n1)) and math.sqrt(n2)==int(math.sqrt(n2)):
        ans += 1
        # print(n1,n2)
print(ans)