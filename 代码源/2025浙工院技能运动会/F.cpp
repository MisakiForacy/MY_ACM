#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = 1e12;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac(){
    int n, m, k;
    cin >> n >> m >> k;
    LL a[n + 1][m + 1];
    LL dp[n + 1][m + 1][k + 1][2];
    for (int i = 1;i <= n;i ++){
        for (int j = 1;j <= m;j ++){
            cin >> a[i][j];
        }
    }
    for (int i = 0;i <= n;i ++){
        for (int j = 0;j <= m;j ++){
            for (int t = 0;t <= k;t ++){
                dp[i][j][t][0] = - inf;
                dp[i][j][t][1] = - inf;
            }
        }
    }
    for (int t = 0;t <= k;t ++){
        dp[1][1][t][0] = a[1][1];
    }
    dp[1][0][0][0] = 0;
    for (int i = 1;i <= n;i ++){
        for (int j = 1;j <= m;j ++){
            for (int t = 0;t <= k;t ++){
                if (t > 1) dp[i][j][t][0] = max(dp[i][j][t][0], dp[i][j][t - 1][1]);
                dp[i][j][t][0] = max(dp[i][j][t][0], dp[i][j - 1][t][0] + a[i][j]);
                if (t > 1) dp[i][j][t][1] = max(dp[i][j][t][1], dp[i][j][t - 1][0]);
                dp[i][j][t][1] = max(dp[i][j][t][1], dp[i - 1][j][t][1] + a[i][j]);
            }
        }
    }
    LL ans = - 1e12;
    for (int t = 0;t <= k;t ++){
        ans = max({ans, dp[n][m][t][0], dp[n][m][t][1]});
    }
    cout << ans << '\n';
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