#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[n+1];
    for (int i=0;i<=n;i++) dp[i] = 999999;
    dp[1] = dp[0] = 0;
    for (int i=2;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        if (!(i&1)){
            dp[i] = min(dp[i],dp[i/2]+1);
        }
    }
    cout << dp[n] << '\n';
}