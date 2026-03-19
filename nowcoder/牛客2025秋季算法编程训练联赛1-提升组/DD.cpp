#include <bits/stdc++.h>
using namespace std;
using LL = long long;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> p(n+1, 0);
    for (int i = 1; i <= n; i++){
        if(s[i]=='B')
            p[i] = 1;
    }
    vector<vector<int>> g(n+1);
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> f(n + 1, 0), sz(n + 1, 1);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto findx = [&](auto findx, int x) -> int {
        if (x != f[x]) {
            f[x] = findx(findx, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int u, int v) -> void {
        u = findx(findx, u);
        v = findx(findx, v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        f[v] = u;
        sz[u] += sz[v];
    };
    for (int u = 1; u <= n; u++){
        if(p[u]) continue;
        for(auto v : g[u]){
            if(!p[v]) merge(u, v);
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++){
        if(!p[i]) continue;
        vector<LL> use;
        use.push_back(1);
        unordered_set<int> used;
        for(auto v: g[i]){
            if(!p[v]){
                int val = findx(findx, v);
                if(used.count(val)) continue;
                used.insert(val);
                use.push_back(sz[val]);
            }
        }
        LL sum = 0;
        for(auto x: use) sum += x;
        for(auto x: use){
            sum -= x;
            ans += x * sum;
        }
    }
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}