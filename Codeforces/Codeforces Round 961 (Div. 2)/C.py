for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    sum = 0
    ok = True
    for i in range(1,n):
        cnt = 0
        if a[i] < a[i-1] and a[i] == 1:
            print(-1)
            ok = False
            break
        while (a[i]<a[i-1]):
            a[i] *= a[i]
            cnt += 1
        sum += cnt
    if (ok):
        print(sum)