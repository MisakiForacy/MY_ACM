#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// const int N = 1e6+10;
int main(){
    LL n;
    cin >> n;
    vector<LL> dp(n+1,0);
    dp[3] = 1;
    dp[4] = 2;
    for (int i=5;i<=n;i++){
        dp[i] = dp[i-1] + (i-1)/2;
    }
    for (int i=3;i<=n;i++){
        dp[i] += dp[i-1];
    }
    cout << dp[n] << '\n';
}