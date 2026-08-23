#include <bits/stdc++.h>

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    LL s = 0, mx = 0, cnt = 0;
    map<int, int> mp;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (~a[i]) s += a[i], mx = max(mx, a[i]), mp[a[i]] ++;
        else cnt ++;
    }
    int t = n - s;
    for (int i = 1;i <= n;i ++) {
        if (~a[i] && a[i] == mx && mp[a[i]] == 1) {
            if (cnt > 0) {
                if (a[i] > (t + cnt - 1) / cnt) {
                    cout << i << ' ';
                }
            } else {
                cout << i << ' ';
            }
        } else if (a[i] == -1 && t > mx) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}