#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const LL inf = 1e18 + 10;
const LL MOD = 1e9 + 7;

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

void solve() {
    LL n, c, Tp;
    cin >> n >> c;
    Tp = c;
    string s;
    cin >> s;
    s = ' ' + s;
    if (s[1] == '0' || s[n] == '0') {
        cout << -1 << '\n';
        return;
    }
    s[1] = s[n] = '1';
    string t = s;
    Z Ans = 1;
    vector<int> ok(n + 1, 0);
    for (int i = 2;i <= n;i ++) {
        if (s[i] == '1') {
            Ans *= Z(2);
            c /= __gcd(c, 2LL);
        } else if (s[i] == '0') {
            Ans *= Z(i - 1);
            c /= __gcd(c, LL(i - 1));
        } else {
            if (i == 2) {
                s[i] = '0';
                Ans *= Z(i - 1);
                c /= __gcd(c, LL(i - 1));
            } else {
                t[i] = '1';
                Ans *= Z(2);
                if (c % 2 == 0) ok[i] = 1;
                c /= __gcd(c, 2LL);
            }
        }
    }
    if (c == 1) {
        for (int i = 2;i <= n;i ++) {
            if (s[i] != '?') {
                if (s[i] == '1') Tp /= __gcd(Tp, 2LL);
                if (s[i] == '0') Tp /= __gcd(Tp, LL(i - 1));
            } else {
                if (i & 1) Tp /= __gcd(Tp, 2LL);
                else {
                    
                }
            }
        }
    }
    if (c == 1) {
        cout << -1 << '\n';
        return;
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}