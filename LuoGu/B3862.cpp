#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
vector<int> G[N];
int vis[N];
int dfs(int n){
    int mx = n;
    if (!G[n].size()){
        return n;
    }
    for (int i=0;i<(int)G[n].size();i++){
        if (!vis[G[n][i]]){
            vis[G[n][i]] = 1;
            mx = max(mx,dfs(G[n][i]));
        }
    }
    return mx;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m,u,v;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> u >> v;
        G[u].push_back(v);
    }
    for (int i=1;i<=n;i++){
        for (int i=1;i<=n;i++) vis[i] = 0;
        cout << dfs(i) << " \n"[i==n];
    }
}