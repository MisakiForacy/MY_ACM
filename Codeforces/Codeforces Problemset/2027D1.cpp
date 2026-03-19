#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
const int N = 3e5+10;
LL a[N],b[N],pre[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        vector<LL> a(n+1,0),b(m+1,0),pre(n+1,0);
        vector<vector<LL>> dp(m+1,vector<LL>(n+1,1e18));
        for (int i=0;i<=m;i++) dp[i][0] = 0;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }
        dp[0][0] = 0;
        for (int i=1;i<=m;i++){
            cin >> b[i];
            int cost = m - i;
            for (int j=1;j<=n;j++) dp[i][j] = dp[i-1][j];
            for (int j=1;j<=n;j++){
                int id = lower_bound(all(pre),pre[j]-b[i]) - begin(pre);
                if (id < j){
                    dp[i][j] = min(dp[i][id]+cost,dp[i][j]);
                }
            }
        }
        cout << (dp[m][n]==1e18?-1:dp[m][n]) << '\n';
    }
}