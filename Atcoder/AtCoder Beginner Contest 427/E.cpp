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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m;
    char c;
    cin >> n >> m;
    int sx, sy;
    vector<vector<int>> a(n + 2, vector<int> (m + 2, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            cin >> c;
            a[i][j] = (c == '#');
            if (a[i][j] == 'T') {
                sx = i, sy = j;
            }
        }
    }
    vector<vector<int>> vis(n + 2, vector<int> (m + 2, 0));
    auto move = [&](vector<vector<int>> pp, int d) -> vector<vector<int>> {
        vector<vector<int>> tmp(n + 2, vector<int> (m + 2, 0));
        if (d == 0)
            for (int i = 1;i <= n;i ++)
                for (int j = 1;j <= m;j ++)
                    tmp[i][j] = pp[i + 1][j];
        if (d == 1)
            for (int i = 1;i <= n;i ++)
                for (int j = 1;j <= m;j ++)
                    tmp[i][j] = pp[i - 1][j];
        if (d == 2)
            for (int i = 1;i <= n;i ++)
                for (int j = 1;j <= m;j ++)
                    tmp[i][j] = pp[i][j + 1];
        if (d == 3)
            for (int i = 1;i <= n;i ++)
                for (int j = 1;j <= m;j ++)
                    tmp[i][j] = pp[i][j - 1];
        for (int i = 0;i <= n + 1;i ++) tmp[i][0] = tmp[i][m + 1] = 0;
        for (int i = 0;i <= m + 1;i ++) tmp[0][i] = tmp[n + 1][i] = 0;
        if (tmp[sx][sy]) tmp[0][0] = -1;
        return tmp;
    };
    auto check = [&](vector<vector<int>> pp) -> int {
        int ok = 1;
        for (int i = 0;i <= n + 1;i ++)
            for (int j = 0;j <= m + 1;j ++)
                if (pp[i][j])
                    ok = 0;
        return ok;
    };
    auto dfs = [&](auto dfs, vector<vector<int>> pp) -> int {
        int step = 0;
        for (int d = 0;d < 4;d ++) {
            vector<vector<int>> nxt = move(pp, d);
            if (!vis[])
        }
        return step;
    };
    int ans = dfs(dfs, a);
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