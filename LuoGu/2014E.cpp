#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const ll inf = LLONG_MAX;
struct edge{
    ll u,w;
    bool operator < (const edge &that) const {
        return w > that.w;
    }
};
void Dijkstra(vector<ll>&dis,int n,int s,vector<edge>G[],vector<bool>H){
    vector<int> vis(n+1,0);
    priority_queue<edge> Q;
    priority_queue<edge> q;
    Q.push({s,0});
    dis[s] = 0;
    while (!Q.empty()){
        ll s = Q.top().u;
        ll w = Q.top().w;
        Q.pop();
        if (vis[s]) continue;
        if (H[s]) q.push({s,w});
        vis[s] = 1, dis[s] = w;
        for (int i=0;i<G[s].size();i++){
            if (G[s][i].w+w < dis[G[s][i].u]){
                dis[G[s][i].u] = G[s][i].w+w;
                Q.push({G[s][i].u,dis[G[s][i].u]});
            }
        }
    }
    while (!q.empty()){
        ll s = q.top().u;
        ll w = q.top().w;
        q.pop();
        if (!vis[s]) continue;
        vis[s] = 0, dis[s] = min(dis[s],w);
        for (int i=0;i<G[s].size();i++){
            q.push({G[s][i].u,G[s][i].w/2+w});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m,h,u,v,w,x;
        cin >> n >> m >> h;
        vector<bool> H(n+1,0);
        vector<edge> G[n+1];
        for (int i=0;i<h;i++){
            cin >> x;
            H[x] = 1;
        }
        for (int i=0;i<m;i++){
            cin >> u >> v >> w;
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        vector<ll> dis1(n+1,inf);
        vector<ll> dis2(n+1,inf);
        Dijkstra(dis1,n,1,G,H);
        Dijkstra(dis2,n,n,G,H);
        ll ans = inf;
        for (int i=1;i<=n;i++){
            ans = min(max(dis1[i],dis2[i]),ans);
        }
        cout << (ans==inf?-1:ans) << '\n';
    }
}