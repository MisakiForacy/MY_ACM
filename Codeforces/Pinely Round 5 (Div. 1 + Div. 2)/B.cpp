#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define LOG 20

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve () {
    int n;
    cin >> n;
    vector<vector<int>> mp(n + 2, vector<int> (n + 2, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            char c;
            cin >> c;
            mp[i][j] = (c == '#');
        }
    }
    int ok = 1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            if (mp[i][j]) {
                for (int ii = i + 2;ii <= n;ii ++) if (mp[ii][j]) ok = 0;
                for (int jj = j + 2;jj <= n;jj ++) if (mp[i][jj]) ok = 0;
            }
        }
    }
    if (!ok) {
        cout << "NO\n";
        return;
    } else {
        vector<vector<int>> tmp = mp;
        auto dfs = [&](auto dfs, int x, int y) -> void {
            mp[x][y] = 0;
            for (int i = 0;i < 4;i ++) {
                if (1 <= x + dx[i] && x + dx[i] <= n && 1 <= y + dy[i] && y + dy[i] <= n) {
                    dfs(dfs, x + dx[i], y + dy[i]);
                }
            }
        };
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= n;j ++) {
                if (mp[i][j]) {
                    dfs(dfs, i, j);
                    break;
                }
            }
        }
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= n;j ++) {
                if (!mp[i][j]) ok = 0;
            }
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    auto check = [&](int x, int y) -> int {
        int cnt = 0;
        for (int i = x;i >= x - 2 && i >= 1;i --) cnt += mp[i][y];
        if (cnt == 3) return 0;
        int cnt = 0;
        for (int i = x;i <= x + 2 && i <= n;i ++) cnt += mp[i][y];
        if (cnt == 3) return 0;
        int cnt = 0;
        for (int i = y;i >= y - 2 && i >= 1;i --) cnt += mp[x][i];
        if (cnt == 3) return 0;
        int cnt = 0;
        for (int i = y;i <= y + 2 && i <= n;i ++) cnt += mp[x][i];
        if (cnt == 3) return 0;
        return 1;
    };
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            if (mp[i][j]) {
                
                for (int ii = i;ii <= n - 1;ii ++) {
                    mp[]
                }
            }
        }
    }
}

int main () {
    // freopen ("in", "r", stdin);
    // freopen ("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}