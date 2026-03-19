#include <bits/stdc++.h>

#define double long double

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

struct node 
{
    LL x, y, id;
    bool operator < (const node&T) const {
        double z1 = sqrt(x * x + y * y);
        double z1_ = sqrt(x * x + (y - 1) * (y - 1));
        double z2 = sqrt(T.x * T.x + T.y * T.y);
        double z2_ = sqrt(T.x * T.x + (T.y - 1) * (T.y - 1));
        // return 2 * y - 1 < 2 * T.y - 1;
        return z1 - z1_ < z2 - z2_;
    }
};

void solve() {
    LL n, w;
    cin >> n >> w;
    vector<pair<LL, LL>> p(n);
    priority_queue<node> q;
    for (int i = 0;i < n;i ++) {
        cin >> p[i].x >> p[i].y;
        q.push({p[i].x, p[i].y, i});
        // if (p[i].x > p[i].y) swap(p[i].x, p[i].y);
    }
    while (w && siz(q)) {
        auto [x, y, id] = q.top();
        q.pop();
        p[id].y -= 1;
        w --;
        if (p[id].y) q.push({p[id].x, p[id].y, id});
    }
    auto cal = [&](PLL v) -> double {
        return sqrt(v.x * v.x + v.y * v.y);
    };
    double ans = 0;
    for (int i = 0;i < n;i ++) {
        ans += cal(p[i]);
    }
    cout << ans << '\n';
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}