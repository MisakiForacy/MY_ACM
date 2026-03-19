#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll l;
    if (!(cin >> n >> m >> l)) return 0;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    vector<ll> y(m);
    for (int i = 0; i < m; ++i) cin >> y[i];

    vector<ll> gaps(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        s += x[i];
        gaps[i] = s;
    }

    vector<ll> pos(m + 1);
    pos[0] = 0;
    for (int i = 1; i <= m; ++i) pos[i] = pos[i - 1] + y[i - 1];

    int j = 0;
    for (int i = 0; i <= m; ++i) {
        ll p = pos[i];
        while (j < n && gaps[j] <= p) ++j; // find first gap > p
        if (j < n && gaps[j] < p + l) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}