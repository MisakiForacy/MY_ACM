#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct haha{
    ll id,x;
};
int main(){
    int n,m;
    ll u,v,w;
    cin >> n >> m;
    vector<haha> G[n+1];
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    int vis[N];
    ll ans[N];
    for (int i=0;i<=n;i++) vis[i] = 0;
    for (int i=0;i<=n;i++) ans[i] = 0;
    for (int i=1;i<=n;i++){
        queue<haha> Q;
        if (G[i].size() && !vis[i]){
            Q.push({i,0});
            while (!Q.empty()){
                auto [id,x] = Q.front();
                Q.pop();
                vis[id] = 1;
                for (int i=0;i<G[id].size();i++){
                    if (!vis[G[id][i].id]){
                        ans[G[id][i].id] = G[id][i].x + x;
                        vis[G[id][i].id] = 1;
                        Q.push({G[id][i].id,ans[G[id][i].id]});
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << " \n"[i==n];
    }
}