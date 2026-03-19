#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string a,b,c;
        cin >> a >> b >> c;
        int n = a.length();
        int m = b.length();
        a = ' ' + a, b = ' ' + b, c = ' ' + c;
        vector<vector<int>> dp(n+2,vector<int>(m+2,1e7));
        dp[0][0] = 0;
        for (int i=1;i<=n;i++) dp[i][0] = c[i]!=a[i];
        for (int i=1;i<=m;i++) dp[0][i] = c[i]!=b[i];
        for (int i=1;i<=n;i++) dp[i][0] += dp[i-1][0];
        for (int i=1;i<=m;i++) dp[0][i] += dp[0][i-1];
        // for (int i=1;i<=m;i++) cout << (c[i]!=b[i]) << " \n"[i==m];
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                dp[i][j] = min(dp[i-1][j]+(c[i+j]!=a[i]),dp[i][j-1]+(c[i+j]!=b[j]));
            }
        }
        // for (int i=0;i<=n;i++){
        //     for (int j=0;j<=m;j++){
        //         cout << dp[i][j] << " \n"[j==m];
        //     }
        // }
        cout << dp[n][m] << '\n';
    }
}