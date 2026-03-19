#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dp(m,vector<int>(n));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin >> dp[i][j];
        }
    }
    for (int i=n-1;i>0;i--){
        for (int j=0;j<m;j++){
            dp[j][i-1] += min(dp[j][i],dp[(j+1)%m][i]);
            // cout << dp[j][i-1] << " \n"[j==m-1];
        }
    }
    int ans = 1e9;
    for (int i=0;i<m;i++){
        ans = min(dp[i][0],ans);
    }
    cout << ans << '\n';
}

/*
2 6 1 8
3 6 2 6
4 2 3 6


*/