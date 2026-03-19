fac = [1,1]
for i in range(2,1000):
    fac.append(fac[len(fac)-1]*i)
for _ in range(int(input())):
    n,a = map(int,input().split())
    cnt = 0
    for c in str(fac[n]):
        if str(a) == c:
            cnt += 1
    print(cnt)