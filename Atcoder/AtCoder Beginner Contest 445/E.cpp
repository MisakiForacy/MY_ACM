#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL N = 1e7 + 1;

vector<LL> p, s(N, 0);

vector<LL> use(N);
const int MOD = 998244353;

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

void init() {
    for (int i = 2;i < N;i ++) {
        if (!s[i]) {
            p.push_back(i);
            use[i] = i;
        }
        for (int j = 0;j < siz(p) && p[j] * i < N;j ++) {
            s[i * p[j]] = 1;
            use[i * p[j]] = min(use[i], p[j]);
            if (i % p[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    vector<map<int, int>> v(n + 1);
    map<int, int> Mx, Mxx, id;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        while (a[i] > 1) {
            v[i][use[a[i]]] ++;
            a[i] /= use[a[i]];
        }
        for (auto [k, vv] : v[i]) {
            if (vv > Mx[k]) {
                Mx[k] = vv;
                id[k] = i;
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (auto [k, vv] : v[i]) {
            if (vv > Mxx[k] && id[k] != i) {
                Mxx[k] = vv;
            }
        }
    }
    Z S = 1;
    for (auto [k, vv] : Mx) S *= Z(k).qmi(vv);
    for (int i = 1;i <= n;i ++) {
        Z ans = S;
        for (auto [k, vv] : v[i]) {
            if (id[k] == i) {
                ans /= Z(k).qmi(vv);
                ans *= Z(k).qmi(Mxx[k]);
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}