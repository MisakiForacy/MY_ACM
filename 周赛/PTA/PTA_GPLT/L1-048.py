Ra,Ca = map(int,input().split())
A = [list(map(int,input().split()))for _ in range(Ra)]
Rb,Cb = map(int,input().split())
B = [list(map(int,input().split()))for _ in range(Rb)]
if Ca != Rb:
    print(f"Error: {Ca} != {Rb}")
else:
    C = [[0 for _ in range(Cb)]for __ in range(Ra)]
    for i in range(Ra):
        for j in range(Cb):
            Multiply = 0
            for k in range(Ca):
                Multiply += A[i][k] * B[k][j];
            C[i][j] = Multiply
    print(f"{Ra} {Cb}")
    for i in range(Ra):
        print(" ".join(map(str,C[i])))