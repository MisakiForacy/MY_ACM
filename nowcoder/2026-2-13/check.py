from math import factorial

def comb(n,k):
    if k<0 or k>n: return 0
    return factorial(n)//(factorial(k)*factorial(n-k))

def ways(sum_, parts):
    if parts == 0:
        return 1 if sum_ == 0 else 0
    if sum_ < parts:
        return 0
    return comb(sum_-1, parts-1)


def formula(n,x,t):
    r = t+1
    k1 = (r+1)//2
    k2 = r//2
    return ways(x,k1)*ways(n-x, r-k1) + ways(x,k2)*ways(n-x, r-k2)


def brute(n,x,t):
    from itertools import combinations
    cnt = 0
    # choose positions of ones
    for ones in combinations(range(n), x):
        s = [0]*n
        for i in ones:
            s[i]=1
        tcount = sum(1 for i in range(n-1) if s[i]!=s[i+1])
        if tcount==t:
            cnt+=1
    return cnt


if __name__=='__main__':
    maxn = 10
    for n in range(1, maxn+1):
        for x in range(0, n+1):
            for t in range(0, n):
                f = formula(n,x,t)
                b = brute(n,x,t)
                if f != b:
                    print('Mismatch at n={}, x={}, t={}: formula={}, brute={}'.format(n,x,t,f,b))
                    # print example sequences
                    print('Searching examples...')
                    from itertools import combinations
                    exs = []
                    for ones in combinations(range(n), x):
                        s = [0]*n
                        for i in ones:
                            s[i]=1
                        tcount = sum(1 for i in range(n-1) if s[i]!=s[i+1])
                        if tcount==t:
                            exs.append(''.join(str(c) for c in s))
                            if len(exs)>=5:
                                break
                    print('Some valid sequences (up to 5):', exs)
                    raise SystemExit(0)
    print('No mismatch up to n=', maxn)
