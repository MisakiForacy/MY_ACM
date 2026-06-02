#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

int use[3][3][4][4];

void init(int x, int y, int r, int w) {
    int ret = 0, base = 0;
    if (x + r - 1 >= 3 || y + w - 1 >= 3) {
        use[x][y][r][w] = 0;
        return;
    }
    for (int i = 0;i < 3;i ++) {
        for (int j = 0;j < 3;j ++) {
            if (x <= i && i <= x + r - 1 && y <= j && j <= y + w - 1) {
                ret |= 1LL << base;
            }
            base ++;
        }
    }
    use[x][y][r][w] = ret;
}

void solve() {
    int n;
    cin >> n;
    vector<LL> g[10];
    for (int i = 1;i <= 9;i ++) for (int j = 0;j < 10;j ++) g[i].push_back(0);
    for (int i = 1;i <= n;i ++) {
        int a, b, v;
        cin >> a >> b >> v;
        g[a * b].push_back(v);
    }
    for (int i = 1;i <= 9;i ++) sort(all(g[i]), greater());
    for (int i = 1;i <= 9;i ++) {
        for (int j = 1;j <= 9;j ++) {
            g[i][j] += g[i][j - 1];
        }
    }
    LL mx = 0;
    mx = max(mx, g[1][8]);
    mx = max(mx, g[2][0] + g[1][6]);
    mx = max(mx, g[2][1] + g[1][4]);
    mx = max(mx, g[2][2] + g[1][2]);
    mx = max(mx, g[2][3] + g[1][0]);
    mx = max(mx, g[3][0] + g[1][5]);
    mx = max(mx, g[3][0] + g[2][0] + g[1][3]);
    mx = max(mx, g[3][0] + g[2][1] + g[1][1]);
    mx = max(mx, g[3][0] + g[2][2]);
    mx = max(mx, g[3][1] + g[1][2]);
    mx = max(mx, g[3][1] + g[2][0] + g[1][0]);
    mx = max(mx, g[3][2]);
    mx = max(mx, g[4][0] + g[1][4]);
    mx = max(mx, g[4][0] + g[2][0] + g[1][2]);
    mx = max(mx, g[4][0] + g[2][1] + g[1][0]);
    mx = max(mx, g[4][0] + g[3][0] + g[1][1]);
    mx = max(mx, g[4][0] + g[3][0] + g[2][0]);
    mx = max(mx, g[6][0] + g[1][2]);
    mx = max(mx, g[6][0] + g[2][0] + g[1][0]);
    mx = max(mx, g[6][0] + g[3][0]);
    mx = max(mx, g[9][0]);
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}