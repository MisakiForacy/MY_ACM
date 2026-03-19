#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;

const LL MOD3 = 998244353;
 
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
    ModInt<MOD> inv(){ ModInt<MOD> a = *this; return a.qmi(MOD-2);}
    ModInt<MOD> friend operator+(ModInt<MOD> a,ModInt<MOD> b){ return (a.x + b.x) % MOD;}
    ModInt<MOD> friend operator-(ModInt<MOD> a,ModInt<MOD> b){ return (a.x - b.x + MOD) % MOD;}
    ModInt<MOD> friend operator*(ModInt<MOD> a,ModInt<MOD> b){ return a.x % MOD * b.x % MOD;}
    ModInt<MOD> friend operator/(ModInt<MOD> a,ModInt<MOD> b){ return a * b.inv();}
    ModInt<MOD> friend operator%(ModInt<MOD> a,ModInt<MOD> b){ return a.x % b.x;}
    bool friend operator<=(ModInt<MOD> a,ModInt<MOD> b){ return a.x <= b.x;}
    bool friend operator< (ModInt<MOD> a,ModInt<MOD> b){ return a.x <  b.x;}
    bool friend operator>=(ModInt<MOD> a,ModInt<MOD> b){ return a.x >= b.x;}
    bool friend operator> (ModInt<MOD> a,ModInt<MOD> b){ return a.x >  b.x;}
    bool friend operator==(ModInt<MOD> a,ModInt<MOD> b){ return a.x == b.x;}
    bool friend operator!=(ModInt<MOD> a,ModInt<MOD> b){ return a.x != b.x;}
    friend ostream& operator<< (ostream& out,ModInt<MOD>& a){ return out << a.x;}
    friend istream& operator>> (istream& in, ModInt<MOD>& a){ return  in >> a.x;}
    ModInt<MOD> operator+= (const ModInt<MOD>& a){ return *this = x + a;}
    ModInt<MOD> operator-= (const ModInt<MOD>& a){ return *this = x - a;}
    ModInt<MOD> operator*= (const ModInt<MOD>& a){ return *this = x * a;}
    ModInt<MOD> operator/= (const ModInt<MOD>& a){ return *this = x / a;}
};
 
using Z = ModInt<MOD3>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<Z> dpl(n + 2, 0), dpr(n + 2, 0);
    dpl[0] = 1, dpr[n + 1] = 1;
    vector<vector<int>> memo(n + 2, vector<int> (n + 2, -1));
    auto check = [&](int l, int r) -> bool {
        int L = l, R = r;
        if (~memo[l][r]) return memo[l][r];
        while (r >= l && s[l] == s[r]) {
            l ++, r --;
            if (~memo[l][r]) return memo[l][r];
        }
        memo[L][R] = r - l < 1;
        return r - l < 1;
    };
    for (int l = 1;l <= n;l ++) {
        for (int len = 1;len <= n;len ++) {
            int r = l + len - 1;
            if (r > n) break;
            if (!check(l, r)) continue;
            dpl[r] += dpl[l - 1];
        }
    }
    for (int r = n;r >= 1;r --) {
        for (int len = 1;len <= n;len ++) {
            int l = r - len + 1;
            if (l < 1) break;
            if (!check(l, r)) continue;
            dpr[l] += dpr[r + 1];
        }
    }
    Z ans = 0;
    for (int l = 1;l <= n;l ++) {
        for (int r = l;r <= n;r ++) {
            if (!check(l, r)) continue;
            ans += dpl[l - 1] * dpr[r + 1] * Z(r - l + 1).qmi(2);
        }
    }
    cout << ans << '\n';
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}