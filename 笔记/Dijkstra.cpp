#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define siz(x) ((int) x.size())
using namespace std;
using LL = long long;

const LL inf = 1e15;

struct node{
    LL v, w;
    bool operator < (const node &that) const {
        return w > that.w;
    }
};

int main(){
    int n, m, st;
    cin >> n >> m >> st;
    vector<vector<node>> g(n + 1);
    for (int i = 1;i <= m;i ++){
        LL u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    priority_queue<node> q;
    vector<LL> dis(n + 1, inf);
    vector<bool> vis(n + 1, 0);
    q.push({st, 0});
    dis[st] = 0;
    while (!q.empty()){
        auto [u, qwq] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]){
            if (qwq + w < dis[v]){
                dis[v] = qwq + w;
                q.push({v, dis[v]});
            }
        }
    }
    for (int i = 1;i <= n;i ++){
        cout << dis[i] << " \n"[i == n];
    }
}