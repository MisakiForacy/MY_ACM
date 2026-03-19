import math
n = int(input())
l,r = map(int,input().split())
idx = int(n/2)
l1 = int(str(l)[:idx])
l2 = int(str(r)[:idx])
r1 = int(str(l)[idx:])
r2 = int(str(r)[idx:])

# print(l1,l2,r1,r2)

f1 = f3 = False

if math.sqrt(l1)==int(math.sqrt(l1)):
    st = int(math.sqrt(l1))
    f1 = True
else:
    st = int(math.sqrt(l1)) + 1
ed = int(math.sqrt(l2))
cntl = ed - st + 1

if int(math.sqrt(l2))==math.sqrt(l2):
    f3 = True

if math.sqrt(r1)==int(math.sqrt(r1)):
    st = int(math.sqrt(r1))
else:
    st = int(math.sqrt(r1)) + 1
ed = int(math.sqrt(int('9'*int(n/2))))

cntr1 = ed - st + 1
cntr2 = int(math.sqrt(int('9'*int(n/2)))) + 1
cntr3 = int(math.sqrt(r2)) + 1


# print(f1,f3)
# print(cntl,cntr1,cntr2,cntr3)
if f1 and f3:
    ans = (cntl-2)*cntr2 + cntr1 + cntr3
elif f1 and (not f3):
    ans = (cntl-1)*cntr2 + cntr1
elif (not f1) and f3:
    ans = (cntl-1)*cntr2 + cntr3
else:
    ans = cntl * cntr2
print(ans)