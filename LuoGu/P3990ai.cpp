#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL MOD = 30011;

template<const LL MOD>
struct ModInt{
    LL x;
    ModInt(LL n = 0){ x = n;}
    ModInt<MOD> qmi(LL k){
        ModInt<MOD> res = 1;
        ModInt a = *this;
        while (k){
            if (k&1) (res.x *= a.x) %= MOD;
            (a.x *= a.x) %= MOD;
            k /= 2;
        }
        return res;
    }
    ModInt<MOD> inv(){ ModInt<MOD> a = *this; return a.qmi(MOD-2); }
    ModInt<MOD> friend operator+(ModInt<MOD> a,ModInt<MOD> b){ return (a.x + b.x) % MOD; }
    ModInt<MOD> friend operator-(ModInt<MOD> a,ModInt<MOD> b){ return (a.x - b.x + MOD) % MOD; }
    ModInt<MOD> friend operator*(ModInt<MOD> a,ModInt<MOD> b){ return a.x % MOD * b.x % MOD; }
    ModInt<MOD> friend operator/(ModInt<MOD> a,ModInt<MOD> b){ return a * b.inv(); }
    ModInt<MOD> friend operator%(ModInt<MOD> a,ModInt<MOD> b){ return a.x % b.x; }
    bool friend operator<=(ModInt<MOD> a,ModInt<MOD> b){ return a.x <= b.x; }
    bool friend operator< (ModInt<MOD> a,ModInt<MOD> b){ return a.x <  b.x; }
    bool friend operator>=(ModInt<MOD> a,ModInt<MOD> b){ return a.x >= b.x; }
    bool friend operator> (ModInt<MOD> a,ModInt<MOD> b){ return a.x >  b.x; }
    bool friend operator==(ModInt<MOD> a,ModInt<MOD> b){ return a.x == b.x; }
    bool friend operator!=(ModInt<MOD> a,ModInt<MOD> b){ return a.x != b.x; }
    friend ostream& operator<< (ostream& out,ModInt<MOD>& a){ return out << a.x; }
    friend istream& operator>> (istream& in, ModInt<MOD>& a){ return  in >> a.x; }
    ModInt<MOD> operator+= (const ModInt<MOD>& a){ return *this = x + a; }
    ModInt<MOD> operator-= (const ModInt<MOD>& a){ return *this = x - a; }
    ModInt<MOD> operator*= (const ModInt<MOD>& a){ return *this = x * a; }
    ModInt<MOD> operator/= (const ModInt<MOD>& a){ return *this = x / a; }
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

    Z ans = result[n - 1] + result[n - 2];
    // 输出答案
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}