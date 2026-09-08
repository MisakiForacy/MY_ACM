#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i];
    sort(all(p));
    int ans = 0;
    for (int j = 0;j < 1LL << n;j ++) {
        vector<int> tp(n);
        for (int i = 0;i < n;i ++) {
            for (int t = 0;t <= i;t ++) {
                tp[i] += ((j >> i & 1) != (j >> t & 1));
            }
        }
        sort(all(tp));
        if (tp == p) {
            for (int i = 0;i < n;i ++) cout << (j >> i & 1) << ' ';
            cout << '\n';
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