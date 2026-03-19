import math
n = int(input())
a = math.floor(pow(n,1/3))
if (a + 1) ** 3 == n:
    print(int(a+1))
else:
    print(int(a))