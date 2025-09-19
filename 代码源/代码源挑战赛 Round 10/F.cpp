#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
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

using Z = ModInt<MOD7>;

void fxy_ac(){
    int n, m;
    cin >> n >> m;
    Z A[n + 1], B[n + 1];
    Z a[n + 1], b[n + 1];
    vector<int> id;
    id.push_back(0);
    A[0] = 1, B[0] = 0;
    for (int i = 1;i <= n;i ++){
        cin >> a[i] >> b[i];
        if (a[i] == 0) id.push_back(i);
    }
    id.push_back(n + 1);
    for (int i = 1;i < siz(id);i ++){
        for (int j = id[i - 1] + 1;j < id[i];j ++){
            if (j == id[i - 1] + 1) A[j] = a[j];
            else A[j] = A[j - 1] * a[j];
        }
    }
    for (int i = 1;i <= n;i ++){
        if (a[i] == 0){
            B[i] = b[i];
        } else{
            
        }
    }
    for (int i = 1;i <= m;i ++){
        Z x, res, add;
        int l, r;
        cin >> x >> l >> r;
        res = (Z)x * (A[r] / A[l - 1]);
        add = (B[r] - B[l - 1]) / (A[n] / A[r]);
        res += add;
        cout << res << '\n';
    }
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}