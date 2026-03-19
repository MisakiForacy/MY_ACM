#include <bits/stdc++.h>
using namespace std;
struct node{
    int id,deep;
};
int dfs(vector<int> G[],int w[],int vis[],int node){
    int cnt = 0;
    if (G[node].size()==1){
        w[node] = 0;
        return 0;
    }
    for (int i=0;i<G[node].size();i++){
        if (!vis[G[node][i]]){
            cnt += dfs(G,w,vis,G[node][i])+1;
            w[node] = cnt;
        }
        vis[G[node][i]] = 1;
    }
    return cnt;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,u,v;
        cin >> n;
        vector<int> G[n+1];
        map<int,int> ans;
        for (int i=0;i<n-1;i++){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        queue<node> Q;
        Q.push({1,0});
        int vis[n+1];
        for (int i=0;i<=n;i++) vis[i] = 0;
        while (!Q.empty()){
            auto [id,deep] = Q.front();
            Q.pop();
            vis[id] = 1;
            for (int i=0;i<G[id].size();i++){
                if (G[G[id][i]].size()==1){
                    ans[deep+1] += 1;
                } else{
                    if (!vis[G[id][i]])
                        Q.push({G[id][i],deep+1});
                }
            }
        }
        int w[n+1];
        for (int i=0;i<=n;i++) vis[i] = 0,w[i] = 0;
        vis[1] = 1;
        dfs(G,w,vis,1);
        for (int i=1;i<=n;i++){
            cout << w[i] << " \n"[i==n];
        }
        int mx = 0;
        int tot = 0;
        cout << '\n';
        for (auto [k,v]:ans){
            mx = max(mx,v);
            tot += v;
        }
        cout << tot - mx << '\n';
    }
}