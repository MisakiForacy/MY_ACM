#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> cnt(n + 1, 0), ccnt(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    vector<int> vis(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        cnt[i] = ccnt[i] = siz(g[i]);
        if (siz(g[i]) == 1) {
            q.push(i);
            vis[i] = 1;
            cnt[i] --;
        }
    }
    map<int, int> qwq;
    for (int i = 1;i <= n;i ++) {
        qwq[ccnt[i]] ++;
        if (ccnt[i] > 5) {
            cout << 0 << '\n';
            return;
        }
    }
    while (siz(q)) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (cnt[v]) {
                cnt[v] --;
                if (cnt[v] > 1) continue;
                q.push(v);
                cnt[v] --;
            }
        }
    }
    // cout << "cnt : ";
    // for (int i = 1;i <= n;i ++) cout << cnt[i] << ' ';
    // cout << '\n';
    vector<pair<int, int>> edge;
    map<pair<int, int>, int> mp;
    for (int i = 1;i <= n;i ++) {
        if (cnt[i]) {
            for (int v : g[i]) {
                if (cnt[v] && !mp.count({v, i})) {
                    mp[{v, i}] = mp[{i, v}] = 1;
                    edge.push_back({i, v});
                }   
            }   
        }   
    }   
    LL ans = 0;
    // cout << siz(edge) << '\n';
    for (auto [x, y] : edge) {
        // cout << x << ' ' << y << '\n';
        qwq[ccnt[x]] --;
        qwq[ccnt[y]] --;
        qwq[ccnt[x] - 1] ++;
        qwq[ccnt[y] - 1] ++;
        if (qwq[5] == 0) ans += n - qwq[4];
        qwq[ccnt[x]] ++;
        qwq[ccnt[y]] ++;
        qwq[ccnt[x] - 1] --;
        qwq[ccnt[y] - 1] --;
    }
    cout << ans << '\n';
}

/*
6
1 2
1 3
1 4
1 5
1 6
2 3
*/

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}