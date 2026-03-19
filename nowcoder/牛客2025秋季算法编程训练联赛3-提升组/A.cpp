#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n, m, p;
    cin >> n >> m >> p;
    LL a[n][m];
    memset(a, 0, sizeof a);
    map<int, pair<int, int>> mp;
    LL Min = (n + 1) * (m + 1), Max = -1;
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < m;j ++) {
            mp[i * m + j] = {i, j};
            Max = max(Max, i * m + j);
            Min = min(Min, i * m + j);
        }
    }
    int re = 0, ub = 0;
    for (int i = 1;i <= p;i ++) {
        LL x, y, val;
        cin >> x >> y >> val;
        LL idx = x * m + y;
        if (idx < Min || idx > Max) re = 1;
        if (re) continue;
        if (x < 0 || x >= n || y < 0 || y >= m) ub = 1;
        a[mp[idx].first][mp[idx].second] = val;
    }
    if (!re) {
        for (int i = 0;i < n;i ++) {
            for (int j = 0;j < m;j ++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        if (ub) {
            cout << "Undefined Behaviour\n";
        } else {
            cout << "Accepted\n";
        }
    } else {
        cout << "Runtime error\n";
    }
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}