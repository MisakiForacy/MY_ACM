#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,t,n;
    cin >> h >> t >> n;
    int dp[h+1][t+1];
    for (int i=0;i<=h;i++){
        for (int j=0;j<=t;j++){
            dp[i][j] = 0;
        }
    }
    for (int i=0;i<n;i++){
        int hi,ti,k;
        cin >> hi >> ti >> k;
        for (int i=h;i>=hi;i--){
            for (int j=t;j>=ti;j--){
                dp[i][j] = max(dp[i][j],dp[i-hi][j-ti]+k);
            }
        }
    }
    cout << dp[h][t] << '\n';
}