for _ in range(int(input())):
    n,b,c = map(int,input().split())
    lo = 0
    hi = n
    while (lo < hi):
        i = (lo + hi) // 2
        l = max(0,(i-1)*b+c-i)
        if c != 0:
            l += 1
        r = n-i+1
        print(i,l,r)
        if (r >= l):
            lo = i + 1
        else:
            hi = i - 1
        # print(i)
    print(lo)