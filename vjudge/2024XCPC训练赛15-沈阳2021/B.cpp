#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5+10;
struct node{
    LL u,w;
};
int f[N],vis[N],a[N],u[N],v[N];
LL w[N];
vector<node> G[N];
void init(int n){
    for (int i=0;i<=n;i++) f[i] = i;
}
int findx(int x){
    if (f[x] != x){
        f[x] = findx(f[x]);
    }
    return f[x];
}
void merge(int a,int b){
    if (a < b) swap(a,b);
    a = findx(a);
    b = findx(b);
    f[a] = b;
}
int main(){
    int n,m;
    cin >> n >> m;
    init(n);
    for (int i=0;i<m;i++){
        cin >> u[i] >> v[i] >> w[i];
        G[u[i]].push_back({v[i],w[i]});
        G[v[i]].push_back({u[i],w[i]});
        merge(u[i],v[i]);
    }
    map<int,node> mp;
    for (int i=1;i<=n;i++){
        mp[findx(i)].w = 1e18;
    }
    LL mi = 1e18;
    for (int i=1;i<=n;i++){
        if (G[i].size()){
            LL sum = 0;
            for (int j=0;j<G[i].size();j++){
                sum += G[i][j].w;
            }
            int ok = 0;
            if (G[i].size() == 1) ok = 1;
            for (int j=1;j<G[i].size();j++){
                if (G[i][j].w != G[i][j-1].w){
                    ok = 1;
                    break;
                }
            }
            if (sum < mp[findx(i)].w && ok){
                mp[findx(i)].w = sum;
                mp[findx(i)].u = i;
            }
        }
    }
    queue<node> q;
    for (auto [k,v]:mp){
        q.push({v.u,0});
        vis[v.u] = 1;
    }
    while (!q.empty()){
        auto [u,w] = q.front();
        q.pop();
        a[u] = w;
        for (int i=0;i<G[u].size();i++){
            if (!vis[G[u][i].u]){
                vis[G[u][i].u] = 1;
                q.push({G[u][i].u,w^G[u][i].w});
            }
        }
    }
    LL ans = 0;
    for (int i=1;i<=n;i++){
        ans += a[i];
        cout << a[i] << " \n"[i==n];
    }
    for (int i=0;i<m;i++){
        if (a[u[i]] ^ a[v[i]] != w[i]){
            ans = -1;
        }
    }
    cout << ans << '\n';
}