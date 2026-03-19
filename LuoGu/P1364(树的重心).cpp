// P1364 O(n)解法 树形DP
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5+10;
vector<int> G[N];
int siz[N],fa[N];
void dfs(int u){
    for (int i=0;i<G[u].size();i++){
        dfs(G[u][i]);
        siz[u] += siz[G[u][i]];
        fa[u] += fa[G[u][i]] + siz[G[u][i]];
    }
}
void dp(int u){
    for (int i=0;i<G[u].size();i++){
        fa[G[u][i]] = fa[u] + siz[1] - 2*siz[G[u][i]];
        dp(G[u][i]);
    }
}
int main(){
    int n,w,u,v;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> w >> u >> v;
        siz[i] = w;
        if (u) G[i].push_back(u);
        if (v) G[i].push_back(v);
    }
    dfs(1);
    dp(1);
    int ans = INT_MAX;
    for (int i=1;i<=n;i++){
        ans = min(ans,fa[i]);
    }
    cout << ans << '\n';
}