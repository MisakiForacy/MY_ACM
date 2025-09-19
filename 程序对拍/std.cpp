#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first
#define y second
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 2;i <= n;i ++) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
    int Min = n + 1;
    vector<int> dep(n + 1, 0);
    auto dfs = [&](auto dfs, int pu, int u) -> void {
        dep[u] = dep[pu] + 1;
        if (!siz(g[u])) Min = min(Min, dep[u]);
        for (auto v : g[u]) {
            if (v == pu) continue;
            dfs(dfs, u, v);
        }
    };
    dfs(dfs, 0, 1);
    map<int, int> mp;
    int cnt = 0;
    for (int i = 1;i <= n;i ++) {
        if (dep[i] <= Min)
            mp[dep[i]] ++;
        else
            cnt ++;
    }
    if (cnt > min(k, n - k)) {
        cout << Min << '\n';
        return;
    }
    vector<int> p;
    for (auto [k, v] : mp) {
        p.push_back(v);
    }
    int rst = min(k, n - k) - cnt;
    sort(all(p));
    vector<int> use;
    for (int i = 0;i < siz(p);i ++) {
        if (rst > 0) {
            if (rst >= p[i]) use.push_back(p[i]);
            rst -= p[i];
        } else {
            use.push_back(p[i]);
        }
    }
    cout << siz(use) << '\n';
}

void brute() { // 暴力

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T; // 多测
    while (T --) {
        fxy_ac();
        // brute();
    }
}