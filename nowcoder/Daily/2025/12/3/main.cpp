#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))

#define x first 
#define y second

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;
 
mt19937_64 rnd(time(0));

struct SegTree
{
    
};

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

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}