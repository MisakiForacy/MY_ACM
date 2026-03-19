#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll u,v,w;
    bool operator < (const haha &that) const {
        if (u!=that.u){
            return u < that.u;
        }
        return v < that.v;
    }
};
int main(){
    ll n,m;
    cin >> n >> m;
    ll ans[n+1];
    bool vis[n+1];
    for (int i=0;i<=n;i++) ans[i] = 0;
    for (int i=0;i<=n;i++) vis[i] = 0;
    ll u,v,w;
    vector<haha> a;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        a.push_back({u,v,w});
    }
    sort(a.begin(),a.end());
    for (int i=0;i<m;i++){
        if (vis[a[i].u] && !vis[a[i].v]){
            ans[a[i].v] = ans[a[i].u] + a[i].w;
            vis[a[i].v] = 1;
        } else if (!vis[a[i].u] && vis[a[i].v]){
            ans[a[i].u] = ans[a[i].v] - a[i].w;
            vis[a[i].u] = 1;
        } else if (!vis[a[i].u] && !vis[a[i].v]){
            ans[a[i].v] = a[i].w;
            vis[a[i].u] = vis[a[i].v] = 1;
        } else{
            ans[a[i].v] = ans[a[i].u] + a[i].w;
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] << " \n"[i==n];
    }
}