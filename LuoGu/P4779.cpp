#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const int inf = 0x3f3f3f3f;
struct haha{
    int id,dis;
    bool operator < (const haha &that) const {
        return dis > that.dis;
    }
};
vector<haha> G[N];
int main(){
    int n,m,s;
    int u,v,w;
    cin >> n >> m >> s;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
    }
    vector<int> weight(n+1,inf);
    vector<int> vis(n+1,0);
    priority_queue<haha> Q;
    Q.push({s,0});
    while (!Q.empty()){
        int id = Q.top().id;
        int dis = Q.top().dis;
        Q.pop();
        if (vis[id]) continue;
        vis[id] = 1, weight[id] = dis;
        for (int i=0;i<G[id].size();i++){
            if (dis+G[id][i].dis<weight[G[id][i].id]){
                weight[G[id][i].id] = dis+G[id][i].dis;
                Q.push({G[id][i].id,weight[G[id][i].id]});
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << weight[i] << " \n"[i==n];
    }
}