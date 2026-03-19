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
    int n, m, k;
    string s;
    cin >> n >> m >> k;
    cin >> s;
    s = ' ' + s;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<vector<int>> dp(2 * k + 1, vector<int> (n + 1, 0));
    for (int i = 1;i <= n;i ++) dp[0][i] = (s[i] == 'A');
    for (int i = 1;i <= 2 * k;i ++) {
        int al = (((2 * k - i) & 1) == 0);
        for (int v = 1;v <= n;v ++) {
            if (g[v].empty()) continue;
            if (al) {
                int ok = 0;
                for (int w : g[v]) {
                    if (dp[i - 1][w]) {
                        ok = 1;
                        break;
                    }
                }
                dp[i][v] = ok;
            } else {
                int ok = 1;
                for (int w : g[v]) {
                    if (!dp[i - 1][w]) {
                        ok = 0;
                        break;
                    }
                }
                dp[i][v] = ok;
            }
        }
    }
    cout << (dp[2 * k][1] ? "Alice\n" : "Bob\n");
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
}