def check(x, k):
    if ((x+1)*(x*2+1) >= k):
        return True
    return False
for _ in range(int(input())):
    k = int(input())
    lo = 0; hi = k
    while (lo <= hi):
        mid = (lo + hi) // 2
        if (check(mid,k)):
            hi = mid - 1
        else:
            lo = mid + 1
    k -= lo*((lo-1)*2+1)
    if (k >= 3*lo + 1):
        print(k-lo*4-1)
    elif (k >= 2*lo + 1):
        print(2*lo+1 - k)
    elif (k > lo):
        print(2*lo+1 - k)
    else:
        print(k - 1)