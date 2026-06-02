#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), nxta(n + 2, n), nxtb(n + 2, n);
    vector<int> nxta1(n + 2, n), nxtb1(n + 2, n), prea(n + 1, 0), preb(n + 1, 0);
    vector<int> posa(n + 2, n + 1), posb(n + 2, n + 1), dp(n + 2, -1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    for (int i = n;i >= 1;i --) {
        posa[a[i]] = min(posa[a[i]], i);
        posb[b[i]] = min(posb[b[i]], i);
        if (a[i] == b[i]) {
            nxta[i] = posa[a[i] + 1];
            nxtb[i] = posb[b[i] + 1];
        } else {
            nxta[i] = posa[1];
            nxtb[i] = posb[1];
        }
        nxta1[i] = posa[1];
        nxtb1[i] = posb[1];
    }
    for (int i = 1;i <= n;i ++) posa[i] = posb[i] = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] == b[i]) {
            prea[i] = preb[i] = posa[a[i]];
            posa[a[i]] = max(posa[a[i]], i);
            posb[b[i]] = max(posb[b[i]], i);
        }
    }
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        int j = i, cur = 1;
        if (a[i] != 1 || b[i] != 1) j = max(i, min(nxta1[j], nxtb1[j]));
        while (j <= n && !(a[j] != b[j] && (a[j] <= cur || b[j] <= cur))) {
            // cout << j << '\n';
            if (a[j] == b[j] && prea[j] && nxta[prea[j]] > j && dp[prea[j]] > j) {
                j = dp[prea[j]];
                break;
            }
            if (j >= min(nxta[j], nxtb[j])) {
                break;
            }
            j = min(nxta[j], nxtb[j]);
            cur ++;
        }
        // cout << i << ' ' << j << '\n';
        dp[i] = j;
        ans += j - i;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}