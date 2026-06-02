#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct node
{
    double x, y, v;
    bool operator < (const node&T) const {
        return v < T.v;
    }
};

const double inf = 1e18;

void solve() {
    double sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    double vf, vp, vh;
    cin >> vf >> vp >> vh;
    int n;
    cin >> n;
    vector<node> p;
    double x, y, v;
    cin >> x >> y >> v;
    p.push_back({x, y, v});
    for (int i = 1;i <= n;i ++) {
        cin >> x >> y >> v;
        if (v > p[0].v) {
            p.push_back({x, y, v});
        }
    }
    p.push_back({fx, fy, inf});
    n = siz(p);
    sort(p.begin(), p.end());
    vector<double> dp(n, inf);
    dp[0] = 0;
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < i;j ++) {
            double dx = abs(p[i].x - p[j].x);
            double dy = abs(p[i].y - p[j].y);
            double t1 = sqrt(dx * dx + dy * dy) / vh;
            double h = t1 * vp;
            double t2 = h / (p[j].v - vp);
            dp[i] = min(dp[i], dp[j] + t1 + t2);
        }
    }
    cout << dp[n - 1] << '\n';
}

int main() {
    cout << fixed << setprecision(16);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}