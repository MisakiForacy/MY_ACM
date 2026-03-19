#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    int dp[n+1][2];
    memset(dp,0x3f,sizeof(dp));
    for (int i=1;i<=n;i++) cin >> a[i];
    dp[0][0] = dp[0][1] = dp[1][1] = 0;
    dp[1][0] = a[1];
    for (int i=2;i<=n;i++){
        dp[i][0] = min(dp[i-1][0]+a[i],dp[i-1][1]+a[i]);
        dp[i][1] = min(dp[i-2][0],dp[i-1][0]);
    }
    cout << min(dp[n][0],dp[n][1]) << '\n';
}