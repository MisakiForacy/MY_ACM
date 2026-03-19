#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> r(n+1,vector<int>(n+1,0));
    for (int i=1;i<n;i++){
        for (int j=i;j<n;j++){
            cin >> r[i][j];
        }
    }
    int dp[n+1];
    for (int i=0;i<=n;i++) dp[i] = 99999999;
    dp[0] = 0;
    for (int j=1;j<=n;j++){
        for (int i=j;i<=n;i++){
            r[j][i] += dp[j-1];
        }
        for (int i=1;i<=j;i++){
            dp[j] = min(dp[j],r[i][j]);
        }
    }
    cout << r[n][n] << '\n';
}