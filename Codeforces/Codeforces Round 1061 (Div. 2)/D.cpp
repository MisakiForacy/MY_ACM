#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    auto ask = [&](int i, int x) -> int {
        cout << "? " << i << ' ' << x << '\n';
        int y;
        cin >> y;
        return y;
    };
    int pp = log2(n);
    vector<int> use(n + 1, 0);
    LL ans = 0;
    for (int i = 0;i <= pp;i ++) {
        int need0 = 0, need1 = 0;
        for (int j = 1;j <= n;j ++) {
            int ok = 1;
            for (int jj = 0;jj < i;jj ++) {
                if ((j >> jj & 1) != (ans >> jj & 1))
                    ok = 0;
            }
            if (!ok) continue;
            if (j & (1LL << i)) need1 ++;
            else need0 ++;
        }
        int cnt0 = 0, cnt1 = 0;
        vector<int> p(n + 1, 0);
        for (int j = 1;j <= n - 1;j ++) {
            if (use[j]) continue;
            p[j] = ask(j, 1LL << i);
            if (p[j]) cnt1 ++;
            else cnt0 ++;
        }
        // cout << i << ": \n";
        // cout << cnt0 << ' ' << need0 << '\n';
        // cout << cnt1 << ' ' << need1 << '\n';
        if (cnt1 != need1) {
            for (int j = 1;j <= n - 1;j ++) {
                if (!p[j]) use[j] = 1;
            }
            ans += 1LL << i;
        } else {
            for (int j = 1;j <= n - 1;j ++) {
                if (p[j]) use[j] = 1;
            }
        }
    }
    cout << "! " << ans << '\n';
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}