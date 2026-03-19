#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;
const LL MOD = 998244353;

template<const LL MOD>
struct ModInt{
    LL x;
    ModInt(LL n = 0){ x = (n % MOD + MOD) % MOD;}
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
    ModInt<MOD> inv(){ ModInt<MOD> a = *this; return a.qmi(MOD-2);}
    ModInt<MOD> friend operator+(ModInt<MOD> a,ModInt<MOD> b){ return (a.x + b.x) % MOD;}
    ModInt<MOD> friend operator-(ModInt<MOD> a,ModInt<MOD> b){ return (a.x - b.x + MOD) % MOD;}
    ModInt<MOD> friend operator*(ModInt<MOD> a,ModInt<MOD> b){ return a.x % MOD * b.x % MOD;}
    ModInt<MOD> friend operator/(ModInt<MOD> a,ModInt<MOD> b){ return a * b.inv();}
    ModInt<MOD> friend operator<=(ModInt<MOD> a,ModInt<MOD> b){ return a.x <= b.x;}
    ModInt<MOD> friend operator< (ModInt<MOD> a,ModInt<MOD> b){ return a.x <  b.x;}
    ModInt<MOD> friend operator>=(ModInt<MOD> a,ModInt<MOD> b){ return a.x >= b.x;}
    ModInt<MOD> friend operator> (ModInt<MOD> a,ModInt<MOD> b){ return a.x >  b.x;}
    ModInt<MOD> friend operator==(ModInt<MOD> a,ModInt<MOD> b){ return a.x == b.x;}
    friend ostream& operator<< (ostream& out,ModInt<MOD>& a){ return out << a.x;}
    friend istream& operator>> (istream& in, ModInt<MOD>& a){ return  in >> a.x;}
    ModInt<MOD> operator+= (const ModInt<MOD>& a){ return *this = x + a;}
    ModInt<MOD> operator-= (const ModInt<MOD>& a){ return *this = x - a;}
    ModInt<MOD> operator*= (const ModInt<MOD>& a){ return *this = x * a;}
    ModInt<MOD> operator/= (const ModInt<MOD>& a){ return *this = x / a;}
};

using Z = ModInt<MOD>;

const LL N = 1e6 + 10;

Z fac[N], invfac[N];

void init() {
    fac[0] = 1;
    for (int i = 1;i < N;i ++) fac[i] = fac[i - 1] * Z(i);
    invfac[N - 1] = Z(1) / fac[N - 1];
    for (int i = N - 2;i >= 0;i --) invfac[i] = invfac[i + 1] * Z(i + 1);
}

Z C(LL n, LL m) {
    if (n < 0 || m < 0 || m > n) return 0;
    return fac[n] * invfac[m] * invfac[n - m];
}

void solve() {
    LL n, x, t;
    cin >> n >> x >> t;
    LL r = t + 1;
    LL k1 = (r + 1) / 2, k2 = r / 2;
    auto cal = [&](LL n, LL m) -> Z {
        if (n == 0 && m == 0) return 1;
        if (n < 0 || m < 0) return 0;
        return C(n - 1, m - 1);
    };
    Z ans = 0;
    ans += cal(x, k1) * cal(n - x, r - k1);
    ans += cal(x, k2) * cal(n - x, r - k2);
    // Z Ans = C(max(0LL, x - 1), max(0LL, k1 - 1)) * C(max(0LL, n - x - 1), max(0LL, r - k1 - 1));
    // Ans += C(max(0LL, x - 1), max(0LL, k2 - 1)) * C(max(0LL, n - x - 1), max(0LL, r - k2 - 1));
    cout << ans << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}