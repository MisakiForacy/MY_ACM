#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> col(n + 1, -1);
    for (int i = 1;i <= n;i ++) {
        if (!(~col[i])) {
            queue<int> q;
            col[i] = 0;
            q.push(i);
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (auto v : g[u]) {
                    if (col[v] == col[u]) {
                        cout << -1 << '\n';
                        return;
                    }
                    if (!(~col[v])) {
                        col[v] = col[u] ^ 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    vector<int> A, B;
    for (int i = 1;i <= n;i ++) {
        if (col[i] == 0) A.push_back(i);
        if (col[i] == 1) B.push_back(i);
    }
    cout << A.size() << '\n';
    for (int x : A) cout << x << ' ';
    cout << '\n';
    cout << B.size() << '\n';
    for (int x : B) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
