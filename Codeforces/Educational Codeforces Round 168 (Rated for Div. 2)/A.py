for _ in range(int(input())):
    ok = False
    s = input()
    for i in range(len(s)-1):
        if (s[i]==s[i+1]):
            s = s[:i+1] + chr(((ord(s[i])+1)-97)%26+97) + s[i+1:]
            ok = True
            break
    if (ok):
        print(s)
    else:
        s = chr(((ord(s[0])+1)-97)%26+97) + s
        print(s)