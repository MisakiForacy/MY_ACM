#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define x first
#define y second
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

using Z = ModInt<MOD3>;

void fxy_ac(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<vector<Z>> dp(n + 1, vector<Z> (k + 1, 0));
    if (s[1] == '0'){
        for (int i = 1;i <= k;i ++) dp[1][i] = 1;
    } else{
        dp[1][s[1] - '0'] = 1;
    }
    for (int i = 2;i <= n;i ++){
        if (s[i] == '0'){
            for (int j = 1;j <= k;j ++){
                for (int l = 1;l <= k;l ++){
                    dp[i][l] += dp[i - 1][j];
                }
                if (i >= k){
                    int p = i - k + 1, ok = 1;
                    for (int v = i - 1;v >= p;v --){
                        if (s[v] != '0' && s[v] - '0' != j){
                            ok = 0;
                            break;
                        }
                    }
                    if (ok){
                        for (int v = p;v <= i;v ++){
                            if (s[v] == '0'){
                                p = v;
                                break;
                            }
                        }
                        dp[i][j] -= dp[i][j] - dp[p - 1][j];
                        cout << j << '~' << dp[p][j] << ' ' << '\n';
                    }
                }
            }
        } else{
            for (int j = 1;j <= k;j ++){
                dp[i][s[i] - '0'] += dp[i - 1][j];
            }
            if (i >= k){
                int p = i - k + 1, ok = 1;
                for (int v = i - 1;v >= p;v --){
                    // cout << v << '*' << s[v] << '\n';
                    if (s[v] != '0' && s[v] != s[i]){
                        ok = 0;
                        break;
                    }
                }
                if (ok){
                    for (int v = p;v <= i;v ++){
                        if (s[v] == '0'){
                            p = v;
                            break;
                        }
                    }
                    dp[i][s[i] - '0'] -= dp[i][s[i] - '0'] - dp[p - 1][s[i] - '0'];
                    cout << dp[p][s[i] - '0'] << '\n';
                }
            }
        }
    }
    Z ans = 0;
    for (int i = 1;i <= k;i ++) ans += dp[n][i];
    cout << ans << '\n';
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 多测
    while (T --){
        fxy_ac();
        // brute();
    }
}