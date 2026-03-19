#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const ll inf = LLONG_MAX;
struct edge{
    int u,w;
    bool operator < (const edge &that) const {
        return w > that.w;
        /*以权重大小排序，权重大的上浮，优先处理*/
    }
};
vector<edge> G[N];
/*建图，存放从当前点出发所能到达的点及其权重*/
void Dijkstra(int n,int s){
    vector<ll> dis(n+1,inf);
    /*每个点的距离设为无穷大*/
    vector<int> vis(n+1,0);
    /*每个点最初标记为未经过*/
    priority_queue<edge> Q;
    dis[s] = 0;
    /*将起始点设为0*/
    Q.push({s,0});
    /*将起始点加入优先队列，权重为0*/
    while (!Q.empty()){
        auto [s,w] = Q.top();
        /*顶部弹出的点记为新的起始点
          因为顶部的点必定是权重最小的点
          */
        Q.pop();
        if (vis[s]) continue;
        /*如果该点已经经过，则无需遍历*/
        vis[s] = 1, dis[s] = w;
        /*否则标记该点，表示已经过*/
        /*将到达该点的距离设为权重*/
        for (int i=0;i<G[s].size();i++){
        /*遍历与该点相连的所有结点*/
            if (w+G[s][i].w<dis[G[s][i].u]){
            /*如果当前权重加上当前点到达下一个结点的代价小于下一个结点的权重*/
            /*则更新*/
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
    int n,m,s;
    int u,v,w;
    cin >> n >> m >> s;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    Dijkstra(n,s);
}