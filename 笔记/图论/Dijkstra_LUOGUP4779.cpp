#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5+10;
const LL inf = LLONG_MAX;
struct edge{
    int u,w;
    bool operator < (const edge&that) const {
        return w > that.w;
    }
};
vector<edge> G[N];
void Dijkstra(int n,int s){
    priority_queue<edge> Q;
    vector<LL> dis(n+1,inf);
    vector<bool> vis(n+1,0);
    dis[s] = 0;
    Q.push({s,0});
    while (!Q.empty()){
        auto [s,w] = Q.top();
        Q.pop();
        if (vis[s]) continue;
        vis[s] = 1;
        for (int i=0;i<G[s].size();i++){
            if (w + G[s][i].w < dis[G[s][i].u]){
                dis[G[s][i].u] = w + G[s][i].w;
                Q.push({G[s][i].u,dis[G[s][i].u]});
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << dis[i] << " \n"[i==n];
    }
}
int main(){
    int n,m,s,u,v,w;
    cin >> n >> m >> s;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    Dijkstra(n,s);
}