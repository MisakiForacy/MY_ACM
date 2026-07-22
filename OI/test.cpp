#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), alls, fa(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], alls.push_back(a[i]);
    sort(alls.begin(), alls.end());
    for (int i = 1;i <= n;i ++) 
        a[i] = lower_bound(alls.begin(), alls.end(), a[i]) - alls.begin() + 1;
    for (int i = 2;i <= n;i ++) cin >> fa[i], g[fa[i]].push_back(i);
    auto dfs = [&](auto dfs, int u) -> void {
            
    };
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    while (T --) solve();
}