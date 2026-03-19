#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[3] = {1,5,11};
    int dp[n+1];
    for (int i=1;i<=n;i++) dp[i] = 999999;
    dp[0] = 0;
    for (int i=0;i<=n;i++){
        for (int j=0;j<3;j++){
            if (i>=a[j]){
                dp[i] = min(dp[i],dp[i-a[j]] + 1);
            }
        }
    }
    cout << dp[n] << '\n';
}