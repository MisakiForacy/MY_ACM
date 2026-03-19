#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<LL>> mp(n+1,vector<LL>(m+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> mp[i][j];
        }
    }
    LL ans = LLONG_MIN;
    vector<vector<LL>> dp(n+1,vector<LL>(m+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (mp[i][j]) dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
            ans = max(ans,dp[i][j]);
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=m;j++){
    //         cout << dp[i][j] << " \n"[j==m];
    //     }
    // }
    cout << ans << '\n';
}