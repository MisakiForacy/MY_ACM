#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int dp[n+1];
    for (int i=1;i<=n;i++) dp[i] = 1;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[j] > a[i]){
                dp[j] = max(dp[j],dp[i] + 1);
            }
        }
    }
    int mx = 0;
    for (int i=1;i<=n;i++){
        mx = max(mx,dp[i]);
    }
    cout << mx << '\n';
}