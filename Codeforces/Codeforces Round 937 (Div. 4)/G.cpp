#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct node{
    string g,w;
};
int vis[20];
vector<int> G[20];
int dfs(int s){
    int deep = 1;
    vis[s] = 1;
    for (int i=0;i<G[s].size();i++){
        if (!vis[G[s][i]]){
            vis[G[s][i]] = 1;
            deep = max(deep,dfs(G[s][i])+1);
        }
    }
    return deep;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<node> a(n+1);
        for (int i=1;i<=n;i++){
            cin >> a[i].g >> a[i].w;
        }
        for (int i=0;i<=16;i++){
            G[i].clear();
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (a[i].g == a[j].g || a[i].w == a[j].w){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        int Max = INT_MIN;
        for (int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            Max = max(Max,dfs(i));
        }
        cout << n - Max << '\n';
    }
}