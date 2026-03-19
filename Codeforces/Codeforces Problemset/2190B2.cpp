#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

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
    Z dp[n + 1][n + 1][4][n + 1];
    /**
     * dp[i][len][k][t] 表示当前状态下的贡献和是多少
     * i 表示取到第i个字符
     * len 表示当前字符串长度
     * k 表示 ")((" 子序列满足了多少位
     * t 表示括号匹配，记')'为-1，'('为+1，t不存在小于0的情况，且结果为0
     */ 
    // for (int i = 0;i <= n;i ++) dp[i][0][0][0] = 1;
    dp[0][0][0][0] = 1;
    for (int i = 1;i <= n;i ++) {
        for (int len = 0;len <= i;len ++) {
            if (s[i] == ')' && len) {
                for (int t = 0;t < len;t ++) {
                    dp[i][len][1][t] += dp[i - 1][len - 1][0][t + 1];
                    dp[i][len][1][t] += dp[i - 1][len - 1][1][t + 1];
                    dp[i][len][2][t] += dp[i - 1][len - 1][2][t + 1];
                    dp[i][len][3][t] += dp[i - 1][len - 1][3][t + 1];
                }
            } else if (len) {
                for (int t = 1;t <= len;t ++) {
                    dp[i][len][0][t] += dp[i - 1][len - 1][0][t - 1];
                    dp[i][len][2][t] += dp[i - 1][len - 1][1][t - 1];
                    dp[i][len][3][t] += dp[i - 1][len - 1][2][t - 1];
                    dp[i][len][3][t] += dp[i - 1][len - 1][3][t - 1];
                }
            }
            for (int t = 0;t <= len;t ++) {
                dp[i][len][0][t] += dp[i - 1][len][0][t];
                dp[i][len][1][t] += dp[i - 1][len][1][t];
                dp[i][len][2][t] += dp[i - 1][len][2][t];
                dp[i][len][3][t] += dp[i - 1][len][3][t];
            }
        }
    }
    Z ans = 0;
    // cout << dp[1][1][0][1] << '\n';
    // cout << dp[n][n][3][0] << '\n';
    for (int i = 3;i <= n;i ++) {
        ans += dp[n][i][3][0] * Z(i - 2);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}