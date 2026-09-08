#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1), in(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= k;i ++) {
        int l, r;
        cin >> l >> r;
        vector<int> p;
        for (int j = l;j <= r;j ++) {
            int val;
            cin >> val;
            p.push_back(val);
        }
        for (int i = 1;i < siz(p);i ++) {
            g[p[i - 1]].push_back(p[i]);
            in[p[i]] ++;
        }
    }
    priority_queue<int, vector<int>, greater<>> q;
    int num = 0;
    for (int i = 1;i <= n;i ++)
        if (!in[i]) q.push(i);
    while (siz(q)) {
        int u = q.top();
        q.pop();
        a[u] = ++ num;
        for (auto v : g[u]) {
            if (-- in[v] == 0) {
                q.push(v);
            }
        }
    }
    if (num == n) {
        for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}