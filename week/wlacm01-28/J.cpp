#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const LL inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2, 1), nxt(n + 2, n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = n;i >= 1;i --) {
        nxt[i] = nxt[i + 1];
        if (a[i + 1] != 1) nxt[i] = i + 1;
    }
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        int j = i;
        LL p = a[i], s = a[i];
        if (k == 1) ans ++;
        while (nxt[j] != n + 1 && a[nxt[j]] <= inf / p) {
            p *= a[nxt[j]];
            s += a[nxt[j]] + nxt[j] - j - 1;
            j = nxt[j];
            // cout << p << ' ' << s << '\n';
            if (p % k == 0) {
                int use = p / k;
                int more = nxt[j] - j - 1;
                if (s <= use && use <= s + more) 
                    ans ++;
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