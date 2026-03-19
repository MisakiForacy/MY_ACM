### 1. 分析递推关系
代码中的递推关系如下：
```cpp
dp[i][j & 1] += dp[i - 1][!(j & 1)] + dp[i][!(j & 1)] + dp[i + 1][!(j & 1)];
```
这表示：
- 当前列 `j` 的 `dp[i]` 依赖于上一列 `j-1` 的 `dp[i-1]`、`dp[i]` 和 `dp[i+1]`。

递推式可以写成：
\[
dp[i][j] = dp[i-1][j-1] + dp[i][j-1] + dp[i+1][j-1]
\]

---

### 2. 转换为矩阵形式
将递推关系转换为矩阵形式。假设 `dp[i][j]` 表示第 `i` 行、第 `j` 列的值，我们可以将状态表示为一个列向量：
\[
\mathbf{dp}[j] = 
\begin{bmatrix}
dp[1][j] \\
dp[2][j] \\
\vdots \\
dp[n][j]
\end{bmatrix}
\]

递推关系可以写成矩阵乘法：
\[
\mathbf{dp}[j] = \mathbf{A} \cdot \mathbf{dp}[j-1]
\]
其中，矩阵 $\mathbf{A}$ 的定义如下：
\[
\mathbf{A} =
\begin{bmatrix}
1 & 1 & 0 & 0 & \cdots & 0 \\
1 & 1 & 1 & 0 & \cdots & 0 \\
0 & 1 & 1 & 1 & \cdots & 0 \\
\vdots & \vdots & \vdots & \ddots & \ddots & \vdots \\
0 & 0 & \cdots & 1 & 1 & 1 \\
0 & 0 & \cdots & 0 & 1 & 1
\end{bmatrix}
\]

---

### 3. 使用矩阵快速幂
为了计算第 `m` 列的值，我们可以通过矩阵快速幂计算：
\[
\mathbf{dp}[m] = \mathbf{A}^{m-1} \cdot \mathbf{dp}[1]
\]

---

### 4. 修改代码
以下是将递推式改为矩阵快速幂的代码实现：

```cpp
#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL MOD = 30011;

template<const LL MOD>
struct ModInt {
    LL x;
    ModInt(LL n = 0) { x = n % MOD; }
    ModInt<MOD> operator*(const ModInt<MOD>& b) const { return (x * b.x) % MOD; }
    ModInt<MOD> operator+(const ModInt<MOD>& b) const { return (x + b.x) % MOD; }
    ModInt<MOD> operator-(const ModInt<MOD>& b) const { return (x - b.x + MOD) % MOD; }
    ModInt<MOD> operator+=(const ModInt<MOD>& b) { return *this = *this + b; }
    ModInt<MOD> operator*=(const ModInt<MOD>& b) { return *this = *this * b; }
};

using Z = ModInt<MOD>;
using Matrix = vector<vector<Z>>;

// 矩阵乘法
Matrix matMul(const Matrix& a, const Matrix& b) {
    int n = a.size();
    Matrix c(n, vector<Z>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

// 矩阵快速幂
Matrix matPow(Matrix a, LL p) {
    int n = a.size();
    Matrix res(n, vector<Z>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1; // 单位矩阵
    while (p) {
        if (p & 1) res = matMul(res, a);
        a = matMul(a, a);
        p >>= 1;
    }
    return res;
}

void solve() {
    LL n, m;
    cin >> n >> m;

    // 初始化转移矩阵 A
    Matrix A(n, vector<Z>(n, 0));
    for (int i = 0; i < n; i++) {
        if (i > 0) A[i][i - 1] = 1; // dp[i-1]
        A[i][i] = 1;               // dp[i]
        if (i < n - 1) A[i][i + 1] = 1; // dp[i+1]
    }

    // 初始状态 dp[1]
    vector<Z> dp(n, 0);
    dp[0] = 1; // dp[1][1] = 1

    // 快速幂计算 A^(m-1)
    A = matPow(A, m - 1);

    // 计算结果 dp[m] = A^(m-1) * dp[1]
    vector<Z> result(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += A[i][j] * dp[j];
        }
    }

    // 输出答案
    cout << result[n - 1] + result[n - 2] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}
```

---

### 5. 代码说明
1. **矩阵初始化**：
   - 矩阵 `A` 表示状态转移关系。
   - `A[i][i-1]` 表示从 `dp[i-1]` 转移到 `dp[i]`。
   - `A[i][i]` 表示从 `dp[i]` 转移到 `dp[i]`。
   - `A[i][i+1]` 表示从 `dp[i+1]` 转移到 `dp[i]`。

2. **矩阵快速幂**：
   - 使用快速幂计算 $A^{m-1}$，时间复杂度为 $O(n^3 \log m)$。

3. **结果计算**：
   - 将初始状态 `dp[1]` 与 $A^{m-1}$ 相乘，得到 `dp[m]`。

---

通过矩阵快速幂，原本的 $O(n \cdot m)$ 时间复杂度优化为 $O(n^3 \log m)$，适合 $m$ 很大的情况。

Similar code found with 1 license type