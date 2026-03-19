#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> dp(n+1,0);
    vector<int> f(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        // f[i] = a[i];
        for (int j=0;j<i;j++){
            if (a[i] >= a[j]){
                // dp[i] = max(dp[i],dp[j]+1);
                if (dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    f[i] = a[i] + f[j];
                }
            }
        }
    }
    // for (int i=1;i<=n;i++){
    //     cout << dp[i] << " \n"[i==n];
    // }
    for (int i=1;i<=n;i++){
        cout << f[i] << " \n"[i==n];
    }
}