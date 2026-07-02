#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

const double inf = 1e18;

struct node
{
    double d, p;
    bool operator < (const node&T) const {
        return d < T.d;
    }
};

void solve() {
    double s, c, l, p;
    int n;
    cin >> s >> c >> l >> p;
    cin >> n;
    vector<node> a(n + 2);
    for (int i = 1;i <= n;i ++) cin >> a[i].d >> a[i].p;
    sort(a.begin() + 1, a.end());
    a[0] = {0, p};
    a[n + 1] = {s, inf};
    vector<vector<double>> f(n + 2, vector<double> (n + 2));
    for (int i = 0;i <= n;i ++) {
        for (int j = i + 1;j <= n + 1;j ++) {
            if (a[j].d - a[i].d <= c * l) f[i][j] = (a[j].d - a[i].d) / l * a[i].p;
            else                      f[i][j] = inf;
        }
    }
    for (int i = 0;i <= n + 1;i ++) {
        for (int j = 0;j <= n + 1;j ++) {
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int k = 1;k <= n;k ++) {
        for (int i = 0;i < k;i ++) {
            for (int j = k + 1;j <= n + 1;j ++) {
                f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
            }
        }
    }
    for (int i = 0;i <= n + 1;i ++) {
        for (int j = 0;j <= n + 1;j ++) {
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << f[0][n + 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
