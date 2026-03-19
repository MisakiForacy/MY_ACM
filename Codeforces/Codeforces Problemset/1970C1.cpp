#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> G[N];
int vis[N];
vector<int> ans;
void bfs(int s){
    queue<pair<int,int>> Q;
    Q.push({s,0});
    vis[s] = 1;
    while (!Q.empty()){
        int node = Q.front().first;
        int step = Q.front().second;
        Q.pop();
        if (G[node].size()==1){
            ans.push_back(step);
        }
        for (int i=0;i<G[node].size();i++){
            if (! vis[G[node][i]]){
                Q.push({G[node][i],step+1});
                vis[G[node][i]] = 1;
            }
        }
    }
}
int main(){
    int n,t,u,v,s;
    cin >> n >> t;
    for (int i=1;i<n;i++){
        cin >> u >> v;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    cin >> s;
    bfs(s);
    int ok = 0;
    for (int i=0;i<ans.size();i++){
        if (ans[i]&1){
            ok = 1;
        }
    }
    cout << (ok?"Ron\n":"Hermione\n");
}