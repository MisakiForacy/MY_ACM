#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> dp(100,0);
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i=4;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout << dp[n] << '\n';
}