#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
const int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), g(1 << n), dp(1 << n, -1);
    for (int i = 0;i < n;i ++) cin >> a[i];
    for (int i = 0;i < 1LL << n;i ++) {
        int ret = 0;
        for (int j = 0;j < n;j ++) {
            if (i >> j & 1) ret ^= a[j];
        }
        g[i] = ret;
    }
    auto sg = [&](auto sg, int state) -> void {
        if (state == 0) {
            dp[state] = 0;
            return;
        }
        int res = 0;
        for (int j = 0;j < n;j ++) {
            if (state >> j & 1) {
                int ns = state - (1 << j);
                if (a[j] > g[ns]) {
                    if (dp[ns] == -1) sg(sg, ns);
                    res |= !dp[ns];
                }
            }
        }
        dp[state] = res;
    };
    sg(sg, (1 << n) - 1);
    cout << (dp[(1 << n) - 1] ? "Left\n" : "Right\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}