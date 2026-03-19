#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

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

vector<vector<int>> use = {
    //  1  2  3  4  5  6  7
    {0, 1, 1, 1, 0, 1, 1, 1}, 
    {0, 0, 0, 1, 0, 0, 1, 0}, 
    {0, 1, 0, 1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1, 0, 1, 1},
    {0, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 1}, 
    {0, 1, 1, 0, 1, 1, 1, 1}, 
    {0, 1, 0, 1, 0, 0, 1, 0}, 
    {0, 1, 1, 1, 1, 1, 1, 1}, 
    {0, 1, 1, 1, 1, 0, 1, 1}, 
};

void solve() {
    LL C;
    vector<Z> p(8), P(10, Z(1));
    cin >> C;
    for (int i = 1;i <= 7;i ++) cin >> p[i];
    for (int i = 1;i <= 7;i ++) p[i] = p[i] / Z(100);
    for (int i = 0;i <= 9;i ++) {
        for (int j = 1;j <= 7;j ++) {
            if (use[i][j]) {
                P[i] *= p[j];
            } else {
                P[i] *= Z(1) - p[j];
            }
        }
    }
    Z Ans = 0;
    for (int A = 0;A <= C;A ++) {
        int B = C - A;
        string As, Bs;
        int Tp = A;
        while (Tp) As.push_back(Tp % 10 + '0'), Tp /= 10;
        while (siz(As) < 4) As.push_back('0');
        Tp = B;
        while (Tp) Bs.push_back(Tp % 10 + '0'), Tp /= 10;
        while (siz(Bs) < 4) Bs.push_back('0');
        Z Pa = 1, Pb = 1;
        for (int i = 0;i < 4;i ++) Pa *= P[As[i] - '0'];
        for (int i = 0;i < 4;i ++) Pb *= P[Bs[i] - '0'];
        Ans += Pa * Pb;
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}