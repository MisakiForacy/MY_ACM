t = int(input()) 
for _ in range(t):
    n, k, s = map(int, input().split())
    p = []
    for  i in range(n):
        a, b = map(int, input().split())
        p.append([a, b])
    p.sort()
    for i in range(n):
        while k > 0 and s < p[i][0]:
            k -= 1
            s *= 2
        if (s >= p[i][0]):
            s += p[i][1]
        else:
            break
    while k > 0:
        s *= 2
        k -= 1
    print(s)