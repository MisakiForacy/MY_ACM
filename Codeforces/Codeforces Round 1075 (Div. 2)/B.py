def min_rollback(n, x, jumps):
    # 初始化 dp 数组，dp[k] 表示到达点 k 的最小倒退次数
    dp = [float('inf')] * (x + 1)
    dp[0] = 0  # 起点不需要倒退

    # 遍历每个点 k
    for k in range(1, x + 1):
        for i in range(n):
            a, b, c = jumps[i]
            # 计算倒退次数
            rollback_count = dp[k - 1] // b if k >= c else 0
            # 如果当前是第 b 次使用第 i 种跳跃方式，则需要倒退
            if rollback_count > 0 and k >= c:
                dp[k] = min(dp[k], dp[k - c] + 1)
            # 普通跳跃
            for j in range(max(0, k - a), k):
                dp[k] = min(dp[k], dp[j])

    # 如果 dp[x] 仍为初始值，说明无法到达点 x
    return dp[x] if dp[x] != float('inf') else -1

# 示例输入
n = 2  # 跳跃方式数量
x = 10  # 目标点
jumps = [
    (5, 3, 2),  # 第一种跳跃方式：最多跳 5，每 3 次倒退 2
    (3, 2, 1)   # 第二种跳跃方式：最多跳 3，每 2 次倒退 1
]

# 调用函数
result = min_rollback(n, x, jumps)
print(result)  # 输出最小倒退次数，或 -1 表示无法到达