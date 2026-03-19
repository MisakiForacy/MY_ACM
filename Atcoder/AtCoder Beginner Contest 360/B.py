s,t = input().split()
ans = "No"
for w in range(len(s)-1):
    for c in range(w):
        temp = ""
        for i in range(c,len(s),w):
            temp += s[i]
        if (temp==t):
            ans = "Yes"
print(ans)