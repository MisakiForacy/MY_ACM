#include <bits/stdc++.h>
using namespace std;
vector<int> G[5005];
int vis[5005];
struct haha{
    int u,v,k;
    bool operator < (const haha &that){
        return k < that.k;
    }
};
bool dfs(int a,int b){
    bool ok = 0;
    if (a==b) return 1;
    for (int i=0;i<(int)G[a].size();i++){
        if (!vis[G[a][i]]){
            vis[G[a][i]] = 1;
            ok = max(ok,dfs(G[a][i],b));
        }
    }
    return ok;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<haha> lik(m);
    for (int i=0;i<m;i++){
        cin >> lik[i].u >> lik[i].v >> lik[i].k;
    }
    sort(lik.begin(),lik.end());
    int ans,cnt;
    ans = cnt = 0;
    for (int i=0;i<m;i++){
        for (int i=0;i<=n;i++) vis[i] = 0;
        if (!dfs(lik[i].u,lik[i].v)){
            G[lik[i].u].push_back(lik[i].v);
            G[lik[i].v].push_back(lik[i].u);
            ans += lik[i].k;
            cnt ++;
        }
    }
    if (cnt != n-1){
        cout << "orz\n";
    } else{
        cout << ans << '\n';
    }
}