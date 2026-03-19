#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

// int m = 99;

struct node1
{
    LL x, y, id;
    bool operator < (const node1&T) const {
        return x < T.x;
    }
};

struct node2
{
    LL x, y, id;
    bool operator < (const node2&T) const {
        return y < T.y;
    }
};

void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    int H = h, W = w;
    vector<PLL> a(n + 1);
    vector<int> use(n + 1, 0);
    vector<PLL> ans(n + 1);
    priority_queue<node1> qx;
    priority_queue<node2> qy;
    for (int i = 1;i <= n;i ++) { 
        cin >> a[i].x >> a[i].y;
        qx.push({a[i].x, a[i].y, i});
        qy.push({a[i].x, a[i].y, i});
    }
    int X = 1, Y = 1;
    while (siz(qx) || siz(qy)) {
        if (siz(qx)) {
            auto [x, y, id] = qx.top();
            if (use[id]) qx.pop();
            if (!use[id] && x == H) {
                use[id] = 1;
                W -= y;
                ans[id] = {X, Y};
                Y += y;
            }
        }
        if (siz(qy)) {
            auto [x, y, id] = qy.top();
            if (use[id]) qy.pop();
            if (!use[id] && y == W) {
                use[id] = 1;
                H -= x;
                ans[id] = {X, Y};
                X += x;
            }
        }
    }
    // cout << '\n';
    for (int i = 1;i <= n;i ++) cout << ans[i].x << ' ' << ans[i].y << '\n';

    // cout << "ok\n";
    // vector<vector<int>> mp(h + 100, vector<int> (w + 100, 0));
    // for (int i = 1;i <= n;i ++) {
    //     for (int j = 0;j < a[i].x;j ++) {
    //         for (int k = 0;k < a[i].y;k ++) {
    //             mp[ans[i].x + j][ans[i].y + k] = 1;
    //         }
    //     }
    // }
    // for (int i = 1;i <= h;i ++) {
    //     for (int j = 1;j <= w;j ++) {
    //         cout << mp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}