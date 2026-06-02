#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> b(500005, 0);
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        b[x] ++;
    }
    LL f = 0, sum = 0, ans = 0;
    for (LL i = 1;i <= 500000;i ++) {
        if (b[i]) {
            if (f) {
                sum += i;
                b[sum] ++;
                b[i] --;
                ans += sum;
                sum = 0;
                f = 0;
            } else {
                sum += i;
                b[i] --;
                i --;
                f = 1;
            }
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