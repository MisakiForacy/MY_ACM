def find_cow_heights(N, H, I, visibility_lines):
    # 初始化牛的身高数组，除了最高的牛，其他牛的身高设为最大可能值
    heights = [float('inf')] * N
    heights[I - 1] = H  # 索引是从0开始的，所以减1

    # 处理直接信息，更新牛的身高
    for A, B in visibility_lines:
        A -= 1  # 转换为0基索引
        B -= 1
        heights[B] = min(heights[B], heights[A])
        # 更新A和B之间所有牛的身高
        for C in range(A + 1, B):
            heights[C] = min(heights[C], heights[A] - 1)

    # 从左到右扫描，确保每头牛的身高不小于前一头牛
    for A in range(1, N):
        if heights[A] < heights[A - 1]:
            heights[A] = heights[A - 1]

    # 从右到左扫描，确保每头牛的身高不小于后一头牛
    for A in range(N - 2, -1, -1):
        if heights[A] < heights[A + 1]:
            heights[A] = heights[A + 1]

    # 确保所有牛的身高非负
    heights = [max(height, 0) for height in heights]

    return heights

# 示例输入
N = 5
H = 10
I = 3
visibility_lines = [(1, 3), (2, 5)]

# 调用函数
result = find_cow_heights(N, H, I, visibility_lines)

# 输出结果
print(result)
