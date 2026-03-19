#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n;
        cin >> n;
        map<LL,vector<LL>> mp;
        vector<LL> a(n+1,0);
        vector<LL> vis;
        map<LL,LL> pass;
        LL ans = 0;
        for (LL i=1;i<=n;i++){
            cin >> a[i];
            if (i>1 && a[i]-(n-i+1)>=0){
                mp[a[i]-(n-i+1)].push_back(i-1);
                if (a[i]-(n-i+1)==0){
                    vis.push_back(0);
                }
            }
        }
        for (int i=0;i<vis.size();i++){
            if (!pass[vis[i]]){
                pass[vis[i]] = 1;
                for (int j=0;j<mp[vis[i]].size();j++){
                    vis.push_back(vis[i]+mp[vis[i]][j]);
                    ans = max(ans,vis[i]+mp[vis[i]][j]);
                }
            }
        }
        cout << ans+n << '\n';
    }
}