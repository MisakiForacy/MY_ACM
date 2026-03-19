t = int(input())
for _ in range(t):
    n,l,r = map(int,input().split())
    rr = 1
    s = input()
    for i in range(n//l,-1,-1):
        if s.count(s[:i]) >= l:
            print(i)
            break