#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second 
using namespace std;
using LL = long long;

const LL MOD = 998244353;

/*
3
8 3
44 5 2018 8 8 2024 8 28
5 4
4 5 5 1 0
5 2
0 0 0 0 0
*/

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i];
    sort(all(p), greater());
    LL ans = p[0];
    ans %= MOD;
    for (int i = 1;i < n;i ++) {
        if (i + k - 2 < n) {
            LL use = 1, ok = 1;
            for (int j = i;j <= i + k - 2;j ++) {
                use *= p[j] % MOD;
                use %= MOD;
                if (p[j] == 0) ok = 0;
            }
            if (!ok) break;
            ans *= use;
            ans %= MOD;
            i += k - 2;
        } else break;
    }
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}