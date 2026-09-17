import sys 
sys.stdout.flush()

a, b, c = map(int, input().split())

print(a, end="\n")

d = int(input())

if (d == 0):
    a *= 2

while (d != 2):
    print(a, end="\n")
    d = int(input())
    if (d == 0):
        a *= 2