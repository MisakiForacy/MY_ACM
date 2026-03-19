s = map(int,input().split('+'))
s = sorted(s,reverse=True)
print(s[0],end='')
for i in s[1:]:
    print(f"+{i}",end='')
print()
print(sum(s))