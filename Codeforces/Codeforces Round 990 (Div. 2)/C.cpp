#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<vector<int>> mp(n,vector<int>(2));
        for (int i=0;i<2;i++){
            for (int j=0;j<n;j++){
                cin >> mp[j][i];
            }
        }
        sort(mp.begin(),mp.end(),[&](vector<int> x,vector<int> y){
            return y[0]+x[1] < y[1]+x[0];
        });
        for (int i=0;i<2;i++){
            for (int j=0;j<n;j++){
                cout << mp[j][i] << " \n"[j==n-1];
            }
        }
        LL ans = LLONG_MIN;
        vector<vector<LL>> pre(2,vector<LL>(n+1,0));
        for (int i=0;i<2;i++){
            for (int j=1;j<=n;j++){
                pre[i][j] = pre[i][j-1] + mp[j-1][i];
            }
        }
        for (int i=1;i<=n;i++){
            ans = max(ans,pre[0][i]-pre[0][0]+pre[1][n]-pre[1][i-1]);
        }
        cout << ans << '\n';
    }
}