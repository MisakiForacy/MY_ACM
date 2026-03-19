#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+10;
using LL = long long;
const LL inf = LLONG_MAX;
struct edge{
    LL u,w;
    bool operator < (const edge&that) const {
        return w > that.w;
    }
};
vector<edge> G[N];
void Dijkstra(vector<LL> a,int n,int s){
    priority_queue<edge> Q;
    vector<bool> vis(2*n+1,0);
    vector<LL> dis(2*n+1,inf);
    dis[s] = 0;
    Q.push({s,0});
    while (!Q.empty()){
        auto [s,w] = Q.top();
        Q.pop();
        if (vis[s]) continue;
        vis[s] = 1, dis[s] = w;
        for (int i=0;i<G[s].size();i++){
            if (w + G[s][i].w < dis[G[s][i].u]){
                dis[G[s][i].u] = w + G[s][i].w;
                Q.push({G[s][i].u,dis[G[s][i].u]});
            }
        }
    }
    LL ans = 0;
    for (int i=n+1;i<=2*n;i++){
        ans = max(ans,dis[i]);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    LL n,m,u,v,w;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        G[u].push_back({n+v,0});
        G[v].push_back({n+u,0});
        G[n+u].push_back({n+v,w});
        G[n+v].push_back({n+u,w});
    }
    vector<LL> a(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        G[0].push_back({i,a[i]});
        G[i].push_back({i+n,0});
    }
    Dijkstra(a,n,0);
}