#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1010];
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n, k;
        cin >> n >> k;
        for (int i=0;i<n;i++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            for (int j=k;j>=1;j--){
                dp[j] = max(dp[j],dp[j-1]+a);
            }
            for (int j=k;j>=2;j--){
                dp[j] = max(dp[j],dp[j-2]+b);
            }
            for (int j=k;j>=3;j--){
                dp[j] = max(dp[j],dp[j-3]+c);
            }
            for (int j=k;j>=4;j--){
                dp[j] = max(dp[j],dp[j-4]+d);
            }
        }
        cout << dp[k] << '\n';
    }
}