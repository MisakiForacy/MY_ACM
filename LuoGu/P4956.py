n = int(input())
flag = False
for x in range(100,-1,-1):
    for k in range(1,101,1):
        if n/52-21*k-7*x==0:
            flag = True
            break
    if flag:
        break
print(f"{x}\n{k}")