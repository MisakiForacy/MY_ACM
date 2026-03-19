s = ""
a,b = input().split()
for i in range(4):
    s += str(int(a[i])%int(b))
print(int(s))