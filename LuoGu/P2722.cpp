#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e4+10;
int main(){
    int m,n,p,t;
    int dp[N];
    cin >> m >> n;
    memset(dp,0,sizeof dp);
    for (int i=0;i<n;i++){
        cin >> p >> t;
        for (int j=t;j<=m;j++){
            dp[j] = max(dp[j],dp[j-t]+p);
        }
    }
    cout << dp[m] << '\n';
}