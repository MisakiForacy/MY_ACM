n = int(input())
forbits = []
for i in range(n):
    s = input()
    forbits.append(s)
f = 0
k = int(input())
string = input()
for i in range(n):
    f += string.count(forbits[i])
    string = string.replace(forbits[i],"-")
string = string.replace("-","<censored>")
if f >= k:
    print(f)
    print("He Xie Ni Quan Jia!")
else:
    print(string)