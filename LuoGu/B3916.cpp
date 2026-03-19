#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
vector<int> G[N];
int vis[N];
void dfs(int n,int mx){
    if (!G[n].size()){
        return;
    }
    for (int i=0;i<(int)G[n].size();i++){
        if (!vis[G[n][i]]){
            vis[G[n][i]] = mx;
            dfs(G[n][i],mx);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m,u,v;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> u >> v;
        G[v].push_back(u);
    }
    for (int i=n;i>=1;i--){
        if (!vis[i]) dfs(i,i);
        vis[i] = max(vis[i],i);
    }
    for (int i=1;i<=n;i++){
        cout << vis[i] << " \n"[i==n];
    }
}