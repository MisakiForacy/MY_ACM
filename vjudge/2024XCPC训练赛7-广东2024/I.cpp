#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
const int N = 2e5+10;
vector<int> G[N];
vector<pair<int,int>> p[N];
vector<int> v(N,0);
vector<int> vis(N,0);
map<int,int> mp;
LL dfs(int id){
    if (mp[id]) return mp[id];
    LL res = 0;
    for (auto [x,y]:p[id]){
        res = max(res,dfs(x)+dfs(y));
    }
    mp[id] = res;
    return res;
}
int main(){
    int n,m;
    cin >> n >> m;
    int a,b,c;
    vector<int> d(n+1,0);
    for (int i=0;i<m;i++){
        cin >> a >> b >> c;
        p[a].push_back({b,c});
        G[b].push_back(a);
        G[c].push_back(a);
        d[a] += 2;
    }
    int ok = 1;
    queue<int> Q;
    for (int i=1;i<=n;i++){
        if (!d[i]) Q.push(i),mp[i] = 1;
    }
    while (!Q.empty()){
        int t = Q.front();
        Q.pop();
        for (int i=0;i<G[t].size();i++){
            d[G[t][i]] --;
            if (!d[G[t][i]]){
                Q.push(G[t][i]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (d[i]){
            ok = 0;
            break;
        }
    }
    LL ans = 0;
    if (ok){
        for (int i=1;i<=n;i++){
            ans += dfs(i);
        }
        if (ans > 1e9){
            cout << -1 << '\n';
        } else{
            cout << ans << '\n';
        }
    } else{
        cout << -1 << '\n';
    }
}