n, m = map(int, input().split())
use = {(0, 0) : 1}
Ans = 0
for i in range(m):
    r, c = map(int, input().split())
    x1, y1 = r, c
    x2, y2 = r, c + 1
    x3, y3 = r + 1, c
    x4, y4 = r + 1, c + 1
    if ((x1, y1) in use) or ((x2, y2) in use) or ((x3, y3) in use) or ((x4, y4) in use):
        continue
    elif x4 > n or y4 > n:
        continue
    else:
        Ans += 1
        use[(x1, y1)] = use[(x2, y2)] = use[(x3, y3)] = use[(x4, y4)] = 1
print(Ans)