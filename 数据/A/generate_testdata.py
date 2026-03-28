import os
import random


def solve(n):
    # 找到k使得 k(k-1)/2 < n <= k(k+1)/2
    k = int((2 * n) ** 0.5)
    while k * (k - 1) // 2 >= n:
        k -= 1
    while k * (k + 1) // 2 < n:
        k += 1
    # 现在k满足 k(k-1)/2 < n <= k(k+1)/2
    d = n - k * (k - 1) // 2  # 在第k条对角线中的位置，从1开始
    if k % 2 == 1:  # 奇数
        numerator = k - d + 1
        denominator = d
    else:  # 偶数
        numerator = d
        denominator = k - d + 1
    return f"{numerator}/{denominator}"


def generate_testcase(test_id, n):
    os.makedirs("testcases", exist_ok=True)
    with open(f"testcases/{test_id}.in", "w") as f:
        f.write(f"{n}\n")
    result = solve(n)
    with open(f"testcases/{test_id}.out", "w") as f:
        f.write(f"{result}\n")


# 生成测试数据
# 小N
small_ns = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for i, n in enumerate(small_ns, 1):
    generate_testcase(i, n)

# 中等N
mid_ns = [100, 500, 1000, 5000, 10000]
for i, n in enumerate(mid_ns, 11):
    generate_testcase(i, n)

# 大N
large_ns = [100000, 500000, 1000000, 5000000, 9999999, 10000000]
for i, n in enumerate(large_ns, 16):
    generate_testcase(i, n)

# 特殊边界：对角线边界
# k(k+1)/2 形式的N
k_vals = [1, 2, 3, 4, 5, 10, 100, 1000, 4472]  # 4472*4473/2 ≈ 10,000,000
for i, k in enumerate(k_vals, 22):
    n = k * (k + 1) // 2
    generate_testcase(i, n)

# 随机N
random.seed(42)
for i in range(30, 41):
    n = random.randint(1, 10000000)
    generate_testcase(i, n)

print("测试数据生成完成，保存在 testcases 目录下。")
