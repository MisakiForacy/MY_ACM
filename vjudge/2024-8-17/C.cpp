#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll dp[55];
    dp[1] = dp[2] = dp[3] = 1;
    for (int i=4;i<=50;i++){
        dp[i] = dp[i-3] + dp[i-1];
    }
    cout << dp[50] << '\n';
}