#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e8;

void fxy_ac() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 2; i <= n; i++) cin >> a[i];
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) g[a[i]].push_back(i);
    int ans = 0;
    auto dfs = [&](auto dfs, int u) -> int {
        int Min = inf;
        for (auto v : g[u]) {
            int val = dfs(dfs, v);
            ans = max(ans, val + 1);
            Min = min(Min, val + 1);
        }
        if (Min > n) Min = 0;
        return Min;
    }; 
    ans = max(ans, dfs(dfs, 1));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        fxy_ac();
    }
    return 0;
}