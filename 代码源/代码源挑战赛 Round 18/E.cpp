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

void fxy_ac(){
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL dp[n + 1][n + 1][2];
    memset(dp, 0x3f, sizeof dp);
    dp[1][0][0] = 0;
    dp[1][0][1] = a[1] + (a[1] == 1 ? 2 : 1);
    for (int i = 2;i <= n;i ++){
        for (int j = 1;j <= i - 1;j ++){
            if (a[i] == a[i - 1]){
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][1] + a[i] + (a[i] == 1 ? 2 : 1));
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][0] + a[i] + (a[i] == 1 ? 2 : 1));
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][0]);
            } else{
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1] + a[i] + (a[i] == 1 ? 2 : 1));
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] + a[i] + (a[i] == 1 ? 2 : 1));
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0]);
            }
        }
    }
    for (int i = 1;i <= n - 1;i ++){
        cout << min(dp[n][i][0], dp[n][i][1]) << " \n"[i == n - 1];
    }
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