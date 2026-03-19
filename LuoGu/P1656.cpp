#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
const int N = 155;
int n,m;
vector<int> G[N];
int vis[N];
struct haha{
    int u,v;
    bool operator < (const haha &that){
        if (that.u != u)return that.u > u;
        return that.v > v;
    }
};
bool dfs(int u,int v){
    int ok = 0;
    if (u==v) return 1;
    for (int i=0;i<(int)G[u].size();i++){
        if (!vis[G[u][i]]){
            vis[G[u][i]] = 1;
            ok = max(ok,(int)dfs(G[u][i],v));
        }
    }
    return ok;
}
bool check(int u,int v){
    G[u].erase(find(all(G[u]),v));
    G[v].erase(find(all(G[v]),u));
    int ok = 0;
    for (int k=0;k<=n;k++) vis[k] = 0;
    if (!dfs(u,v)){
        ok = 1;
    }
    G[u].push_back(v);
    G[v].push_back(u);
    return ok;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<haha> ans;
    vector<haha> rd;
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        rd.push_back({u,v});
    }
    for (int i=0;i<m;i++){
        if (check(rd[i].u,rd[i].v)){
            int uu = min(rd[i].u,rd[i].v);
            int vv = max(rd[i].u,rd[i].v);
            ans.push_back({uu,vv});
        }
    }
    sort(ans.begin(),ans.end());
    for (int i=0;i<(int)ans.size();i++){
        cout << ans[i].u << ' ' << ans[i].v << '\n';
    }
}