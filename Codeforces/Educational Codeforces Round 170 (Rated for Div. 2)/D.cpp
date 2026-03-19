#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,m,cnt;
    cnt = 0;
    cin >> n >> m;
    vector<int> S(2e5+1,0);
    vector<int> I(2e5+1,0);
    vector<vector<int>> dp(m+1,vector<int>(m+1,0));
    int ans = INT_MIN;
    for (int i=0;i<n;i++){
        int r;
        cin >> r;
        if (r > 0){
            I[r] ++;
        } else if (r < 0){
            r = -r;
            S[r] ++;
        } else{
            for (int j=1;j<=m;j++){
                S[j] += S[j-1];
                I[j] += I[j-1];
            }
            for (int j=0;j<cnt;j++){
                int k = cnt - j - 1;
                dp[j+1][k] = max(dp[j+1][k],dp[j][k]+S[j+1]+I[k]);
                dp[j][k+1] = max(dp[j][k+1],dp[j][k]+S[j]+I[k+1]);
                ans = max({ans,dp[j][k+1],dp[j+1][k]});
            }
            cnt ++;
            for (int j=1;j<=m;j++){
                S[j] = I[j] = 0;
            }
        }
    }
    for (int i=1;i<=m;i++){
        S[i] += S[i-1];
        I[i] += I[i-1];
    }
    for (int j=0;j<cnt;j++){
        int k = cnt - j - 1;
        dp[j+1][k] = max(dp[j+1][k],dp[j][k]+S[j+1]+I[k]);
        dp[j][k+1] = max(dp[j][k+1],dp[j][k]+S[j]+I[k+1]);
        ans = max({ans,dp[j+1][k],dp[j][k+1]});
    }
    cout << ans << '\n';
}