#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    // vector<vector<string>> a(n + 1, vector<string> (m + 1));
    map<string, vector<pair<int, int>>> mp;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            string s = "";
            for (int t = 0;t < k;t ++) {
                char c;
                cin >> c;
                s.push_back(c);
            }
            // cout << s << '\n';
            // cout << i << ' ' << j << ' ' << s << '\n';
            mp[s].push_back({i, j});
        }
    }
    // cout << "ok\n";
    for (auto [k, v] : mp) {
        if (siz(v) == 1) {
            cout << v[0].x << ' ' << v[0].y << '\n';
            return;
        }
    }
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}