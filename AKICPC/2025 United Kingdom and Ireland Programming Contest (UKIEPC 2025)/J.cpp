#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    vector<vector<int>> g(27);
    vector<int> in(27, 0), out(27, 0);
    vector<array<char, 3>> p(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    cin >> s;
    map<char, int> use;
    for (auto c : s) use[c] = 1;
    for (int i = 1;i <= n;i ++) {
        char a, b, op;
        a = p[i][0], op = p[i][1], b = p[i][2];
        if (!use[a] || !use[b]) continue;
        if (op == '<') {
            out[a - 'a' + 1] ++, in[b - 'a' + 1] ++;
            g[a - 'a' + 1].push_back(b - 'a' + 1);
        } else {
            out[b - 'a' + 1] ++, in[a - 'a' + 1] ++;
            g[b - 'a' + 1].push_back(a - 'a' + 1);
        }
    }
    int tot = 1, ok = 1;
    vector<int> val(27, 0);
    auto dfs = [&](auto dfs, int u) -> void {
        val[u] = tot ++;
        for (auto v : g[u]) {
            if (val[v]) {
                ok = 0;
                continue;
            }
            dfs(dfs, v);
        }
    };
    for (int i = 1;i <= 26;i ++) {
        if (out[i] && !in[i]) {
            dfs(dfs, i);
        }
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n";
    } else {
        sort(all(s), [&](char x, char y) {
            return val[x - 'a' + 1] < val[y - 'a' + 1];
        });
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}