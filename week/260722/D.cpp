#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1, 0), f(n + 1, 0), pos(n + 1);
    for (int i = 1;i <= n;i ++) cin >> p[i], pos[p[i]] = i;
    int l = pos[1], r = pos[1];
    for (int i = 1;i <= n;i ++) {
        l = min(l, pos[i]);
        r = max(r, pos[i]);
        if (r - l + 1 != i) cout << 0;
        else cout << 1;
    }
    cout << '\n';
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
