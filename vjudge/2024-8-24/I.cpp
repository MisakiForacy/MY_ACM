#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
const int N = 505;
vector<int> G[N];
int vis[N];
int city[N];
bool dfs(int u,int v){
    bool ok = 0;
    if (u==v) return 1;
    for (int i=0;i<(int)G[u].size();i++){
        if (!vis[G[u][i]]){
            vis[G[u][i]] = 1;
            ok = max(ok,dfs(G[u][i],v));
        }
    }
    return ok;
}
bool check(int n){
    for (int i=0;i<n;i++){
        if (!city[i]) return 0;
    }
    return 1;
}
int main(){
    int n,m,u,v,k,x;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> k;
    int ok = 1;
    for (int i=0;i<k;i++){
        cin >> x;
        city[x] = 1;
        for (int j=0;j<G[x].size();j++){
            G[G[x][j]].erase(find(all(G[G[x][j]]),x));
        }
        ok = 0;
        for (int j=0;j<G[x].size();j++){
            for (int k=j+1;k<G[x].size();k++){
                for (int i=0;i<=n;i++) vis[i] = 0;
                if (!dfs(G[x][j],G[x][k])){
                    ok = 1;
                }
            }
        }
        if (ok){
            printf("Red Alert: City %d is lost!\n",x);
        } else{
            printf("City %d is lost.\n",x);
        }
    }
    if (check(n)){
        printf("Game Over.\n");
    }
}