T = int(input())
for _ in range(T):
    A = input().split('.')
    B = input().split('.')
    ans = 'Equal'
    # print(A)
    # print(B)
    for i in range(min(len(A), len(B))):
        if int(A[i]) > int(B[i]):
            ans = 'A'
            break
        elif int(B[i]) > int(A[i]):
            ans = 'B'
            break
    if ans == 'Equal':
        if len(A) > len(B):
            ans = 'A'
        elif len(B) > len(A):
            ans = 'B'
    print(ans)