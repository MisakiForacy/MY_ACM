#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5+10;
LL dp[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,W;
    int v,w,m;
    cin >> n >> W;
    for (int i=0;i<n;i++){
        cin >> v >> w >> m;
        for (int j=1;j<=m;j++){
            if (j*w > W) break;
            for (int k=W;k>=w;k--){
                dp[k] = max(dp[k],dp[k-w]+v);
            }
        }
    }
    cout << dp[W] << '\n';
}