#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<PLL> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end(), [&](PLL x, PLL y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });
    int v = 1;
    for (int i = 0;i < n;i ++) {
        if (!(p[i].first <= v && p[i].second >= v)) {
            cout << "No\n";
            return;
        }
        v ++;
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}