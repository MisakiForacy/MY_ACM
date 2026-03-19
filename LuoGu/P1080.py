n=int(input())

if(n%3==0):

else:
    m=n//2
    print(m)
    for i in range(1,m+1):
        print(i*2-1,i*2)
    for i in range(1,m+1):
        print(i,m+i)
