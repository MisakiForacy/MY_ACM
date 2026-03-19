#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,m,k;
        cin >> n >> m >> k;
        vector<int> a(m),q(k);
        for (int i=0;i<m;i++) cin >> a[i];
        for (int i=0;i<k;i++) cin >> q[i];
        string ans = "";
        if (k == n){
            for (int i=0;i<m;i++){
                ans.push_back('1');
            }
            cout << ans << '\n';
        } else if (k < n-1){
            for (int i=0;i<m;i++){
                ans.push_back('0');
            }
            cout << ans << '\n';
        } else{
            vector<int> vis(n+1,0);
            for (int i=0;i<k;i++){
                vis[q[i]] = 1;
            }
            for (int i=0;i<m;i++){
                ans.push_back(vis[a[i]] ? '0' : '1');
            }
            cout << ans << '\n';
        }
    }
}