for _ in range(int(input())):
    n = input()
    if len(n) > 2:
        if n[:2]=='10' and n[2]!='0' and int(n[2:])>=2:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")