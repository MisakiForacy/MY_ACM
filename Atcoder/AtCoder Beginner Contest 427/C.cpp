#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second 
using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

mt19937_64 rng(time(0));

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    map<pair<int, int>, int> mp;
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}] = mp[{v, u}] = 1;
    }
    int ans = m;
    for (int i = 0;i < (1LL << n);i ++) {
        vector<int> p(n + 1, 0);
        for (int j = 1;j <= n;j ++) {
            if (i >> (j - 1) & 1)
                p[j] = 1;
            else
                p[j] = 0;
        }
        int cnt = 0;
        for (int j = 1;j <= n;j ++) {
            for (int k = 1;k < j;k ++) {
                if (p[j] != p[k]) {
                    if (mp.count({j, k})) {
                        cnt ++;
                    }
                }
            }
        }
        ans = min(ans, m - cnt);
    }
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve();
    }
}