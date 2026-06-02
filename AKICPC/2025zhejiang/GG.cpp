#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const double eps = 1e-10;

struct nd 
{
    double l, k;
    bool operator < (const nd&T) const {
        double cur = 1 + l * k / 100;
        double nxt = 1 + l * (k + 1) / 100;
        double Tcur = 1 + T.l * T.k / 100;
        double Tnxt = 1 + T.l * (T.k + 1) / 100;
        return (nxt / cur) < (Tnxt / Tcur); 
    }
};

void solve(int T) {
    int n, m;
    cin >> n >> m;
    vector<double> l(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> l[i];
    sort(l.begin() + 1, l.end(), greater());
    double lo = 1, hi = 5;
    auto check = [&](double x) -> int {
        int use = 0;
        // cout << x << ":\n";
        for (int i = 1;i <= n;i ++) {
            int k = (100 * (x - 1) - l[i]) / (l[i] - l[i] * x);
            if (k * (l[i] - l[i] * x) != 100 * (x - 1) - l[i]) k ++;
            // for (int j = 20;j >= 0;j --) {
            //     int Tp = k + (1LL << j);
            //     if (Tp > m) continue;
            //     if ((Tp * l[i] / 100 + 1) / ((Tp - 1) * l[i] / 100 + 1) < x) continue;
            //     k = Tp;
            // }
            // cout << l[i] << ' ' << k << '\n';
            use += k;
        }
        // getchar();
        return use <= m;
    };
    // cout << check(9.00 /8 - 1e-10) << '\n';
    while (hi - lo > eps) {
        double mid = (lo + hi) / 2;
        if (check(mid)) 
            hi = mid;
        else
        lo = mid;
    }
    int use = 0;
    vector<LL> k(n + 1);
    priority_queue<nd> q;
    for (int i = 1;i <= n;i ++) {
        // for (int j = 20;j >= 0;j --) {
        //     int Tp = k[i] + (1LL << j);
        //     // if (Tp > m) continue;
        //     if ((Tp * l[i] / 100 + 1) / ((Tp - 1) * l[i] / 100 + 1) < hi) continue;
        //     k[i] = Tp;
        // }
        k[i] = (100 * (hi - 1) - l[i]) / (l[i] - l[i] * hi);
        if (k[i] * (l[i] - l[i] * hi) != 100 * (hi - 1) - l[i]) k[i] ++;
        use += k[i];
        q.push({l[i], k[i]});
    }
    m -= use;
    // cout << lo << '\n';
    // cout << m << '\n';
    while (m --) {
        auto [ll, kk] = q.top();
        q.pop();
        q.push({ll, kk + 1});
    }
    double ans = 1;
    while (siz(q)) {
        auto [ll, kk] = q.top();
        q.pop();
        ans *= 1 + ll * kk / 100;
    }
    cout << ans << '\n';
    // cout << check(9.00/8-eps) << '\n';
}

/*
2
3 5
50 100 50
10 1000000
1 2 3 4 5 6 7 8 9 10
*/

int main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    // while (T --) solve();
    for (int i = 1;i <= T;i ++) solve(i);
}