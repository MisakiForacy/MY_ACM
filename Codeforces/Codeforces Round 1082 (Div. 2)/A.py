def can_reach(x, y):
    # 枚举 c
    for c in range(0, 10**6):  # c 不会太大，否则 x 会远大于 0
        a = y + c
        if a < 0:
            continue
        b_numer = x - 2*y - 6*c
        if b_numer < 0:
            continue
        if b_numer % 3 != 0:
            continue
        b = b_numer // 3
        if b >= 0:
            return True
        # 如果 b 已经小于 0，c 继续增大只会让 b 更小，可以 break
        if x - 2*y - 6*c < 0:
            break
    return False

# 输入
x, y = map(int, input().split())
print("Yes" if can_reach(x, y) else "No")