#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<LL> c(n + 1);
    LL use = 0, need = 0, ans = 0, cnt = 0;
    for (int i = 1;i <= n;i ++) {
        cin >> c[i];
        use += max(0LL, c[i] / 2 - 1);
        if (c[i] == 1) need ++;
        else {
            ans += c[i];
            cnt ++;
        }
    }
    if (ans <= 3) {
        if (need) ans ++;
    } else {
        if (cnt > 1) {
            ans += min(need, use);
        } else {
            ans += min(ans / 2, need);
        }
    }
    if (ans < 3) ans = 0;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}