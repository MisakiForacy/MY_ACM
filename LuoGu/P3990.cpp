#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, -1};
const int dy[] = {1, 0, 0};

const LL inf = 1e18;
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
using M = vector<vector<Z>>;

LL n, m;

M mul(M &A, M &B) {
    M c(n + 2, vector<Z> (n + 2, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            for (int k = 1;k <= n;k ++) {
                c[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return c;
}

M qmi(M &A, LL k) {
    M base(n + 2, vector<Z> (n + 2, 0));
    for (int i = 1;i <= n;i ++) base[i][i] = 1;
    while (k) {
        if (k & 1) base = mul(base, A);
        A = mul(A, A);
        k >>= 1;
    }
    return base;
}

void solve() {
    cin >> n >> m;
    // If m <= 2 there is no valid path to reach column m-1 at rows n-1 or n
    if (m <= 2) {
        cout << 0 << '\n';
        return;
    }

    // Build transition matrix A (1..n). From i you can go to i-1, i, i+1.
    M A(n + 2, vector<Z> (n + 2, 0));
    for (int i = 1; i <= n; ++i) {
        A[i][i] = 1;
        if (i > 1) A[i][i - 1] = 1;
        if (i < n) A[i][i + 1] = 1;
    }

    // We start at j = 1 with a vector v where v[1] = 1.
    // We need the state at j = m-1, which is A^(m-2) * v.
    M P = qmi(A, m - 1);

    // Since v has 1 at index 1 only, the resulting vector is simply column 1 of P.
    Z ans = P[n][1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
