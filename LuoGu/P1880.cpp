// 4
// 4 5 9 4
// 4 14 4       14
// 4 18         14 + 18
// 22           14 + 18 + 22 = 54 Max
// 4 5 9 4
// 8 5 9        8
// 13 9         8 + 13
// 22           8 + 13 + 22 = 43 Min
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    vector<int> a(n+2,0);
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++){
        for (int j=n;j>=i;j--){
            dp[i][j] = max(dp[i-1][j]*2+a[i-1],dp[i][j+1]*2+a[j+1]);
        }
    }
    for (int i=1;i<=n;i++){
        dp[i][i] += a[i];
    }
    
}