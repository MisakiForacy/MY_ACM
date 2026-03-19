n = int(input())
m = list(map(float,input().split()))
s = sum(m)
s /= n+1
print("{:.6f}".format(s*2),end=" ")
for _ in range(1,n):
    print("{:.6f}".format(s),end=" ")