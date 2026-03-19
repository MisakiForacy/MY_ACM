#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,w,d;
    cin >> n >> m;
    vector<ll> dp(m+1,0);
    for (int i=0;i<n;i++){
        cin >> w >> d;
        for (int j=m;j>=w;j--){
            dp[j] = max(dp[j],dp[j-w]+d);
        }
    }
    cout << dp[m] << '\n';
}