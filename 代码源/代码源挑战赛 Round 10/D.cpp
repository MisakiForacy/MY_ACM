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

void fxy_ac(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    LL dp[n + 1][n + 1][2];
    memset(dp, 0, sizeof dp);
    /*
        表示第i轮的第j个球颜色为k的可能次数
        dp[i][j][0] = dp[i - 1][j][0] * dp[i - 1][j + 1][0]
                    + dp[i - 1][j][0] * dp[i - 1][j + 1][1]
                    + dp[i - 1][j][1] * dp[i - 1][j + 1][0]
        dp[i][j][1] = dp[i - 1][j][1] * dp[i - 1][j + 1][1]
                    + dp[i - 1][j][1] * dp[i - 1][j + 1][0]
                    + dp[i - 1][j][0] * dp[i - 1][j + 1][1]
    */
    for (int i = 1;i <= n;i ++) dp[0][i][s[i] == 'b'] = 1;
    for (int i = 1;i <= n - 1;i ++){
        for (int j = 1;j <= n - i;j ++){
            (dp[i][j][0] += dp[i - 1][j][0] * dp[i - 1][j + 1][0] % MOD3) %= MOD3;
            (dp[i][j][0] += dp[i - 1][j][0] * dp[i - 1][j + 1][1] % MOD3) %= MOD3;
            (dp[i][j][0] += dp[i - 1][j][1] * dp[i - 1][j + 1][0] % MOD3) %= MOD3;
            (dp[i][j][1] += dp[i - 1][j][1] * dp[i - 1][j + 1][1] % MOD3) %= MOD3;
            (dp[i][j][1] += dp[i - 1][j][0] * dp[i - 1][j + 1][1] % MOD3) %= MOD3;
            (dp[i][j][1] += dp[i - 1][j][1] * dp[i - 1][j + 1][0] % MOD3) %= MOD3;
        }
    }
    cout << dp[n - 1][1][0] << ' ' << dp[n - 1][1][1] << '\n';
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