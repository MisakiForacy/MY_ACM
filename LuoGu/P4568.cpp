#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
using LL = long long;
const LL inf = LLONG_MAX;
struct edge{
    LL u,w;
    bool operator < (const edge&that) const {
        return w > that.w;
    }
};
vector<edge> G[N];
void Dijkstra(int n,int k,int s,int t){
    priority_queue<edge> Q;
    vector<LL> dis(n*k+1,inf);
    vector<bool> vis(n*k+1,0);
    dis[s] = 0;
    Q.push({s,0});
    while (!Q.empty()){
        auto [s,w] = Q.top();
        Q.pop();
        if (vis[s]) continue;
        vis[s] = 1, dis[s] = w;
        for (int i=0;i<(int)G[s].size();i++){
            if (w + G[s][i].w < dis[G[s][i].u]){
                dis[G[s][i].u] = w + G[s][i].w;
                Q.push({G[s][i].u,dis[G[s][i].u]});
            }
        }
    }
    LL ans = inf;
    for (int i=0;i<n*k;i+=n){
        ans = min(ans,dis[i+t]);
    }
    cout << ans << '\n';
}
int main(){
    LL n,m,k,s,t,a,b,c;
    cin >> n >> m >> k;
    cin >> s >> t;
    k ++;
    for (int i=0;i<m;i++){
        cin >> a >> b >> c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        for (int j=1;j<k;j++){
            G[n*j+a].push_back({n*j+b,c});
            G[n*j+b].push_back({n*j+a,c});
            G[n*(j-1)+a].push_back({n*j+b,0});
            G[n*(j-1)+b].push_back({n*j+a,0});
        }
    }
    Dijkstra(n,k,s,t);
}