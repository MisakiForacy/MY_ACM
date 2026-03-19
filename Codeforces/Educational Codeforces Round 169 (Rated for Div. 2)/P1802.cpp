#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    T = 1;
    while (T--){
        ll n,x;
        ll l,w,u;
        cin >> n >> x;
        vector<ll> dp(x+1,0);
        for (int i=0;i<n;i++){
            cin >> l >> w >> u;
            for (int j=x;j>=u;j--){
                dp[j] = max(dp[j]+l,dp[j-u] + w);
            }
            for (int j=u-1;j>=0;j--){
                dp[j] += l;
            }
        }
        cout << dp[x] * 5 << '\n';
    }
}