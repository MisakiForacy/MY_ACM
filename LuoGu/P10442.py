s = input()
t = input()
cnt = 0
s = list(s)
t = list(t)
var = [1 for _ in range(len(t))]
for i in s:
    if i in t and var[t.index(i)]:
        cnt += 1
        var[t.index(i)] = 0
print(cnt)