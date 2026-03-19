#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    int Max = 0;
    for (int i=0;i<m;i++) cin >> a[i], Max = max(Max,a[i]);
    vector<int> b(n+Max+1,0);
    vector<int> dp(n+Max+1,INT_MIN);
    for (int i=0;i<n;i++) cin >> b[i];
    dp[0] = b[0];
    for (int i=1;i<=n+Max;i++){
        for (int j=0;j<m;j++){
            if (i >= a[j]){
                dp[i] = max(dp[i-a[j]]+b[i],dp[i]);
            }
        }
    }
    int ans = INT_MIN;
    // for (int i=0;i<=n+Max;i++){
    //     cout << dp[i] << " \n"[i==n+Max];
    // }
    for (int i=n;i<=n+Max;i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << '\n';
}