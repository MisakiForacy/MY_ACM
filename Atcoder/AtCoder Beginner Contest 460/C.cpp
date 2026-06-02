#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1), b(m + 1);
    multiset<LL> bs;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= m;i ++) cin >> b[i], bs.insert(b[i]);
    sort(all(a)), sort(all(b));
    int l = 1, ans = 0;
    for (int i = 1;i <= n;i ++) {
        auto pos = bs.upper_bound(2 * a[i]);
        if (pos != bs.begin()) {
            pos --;
            bs.erase(pos);
            ans ++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
