#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

const LL mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    int f[2];
    f[1] = f[0] = 0;
    LL ans = 1;
    for (int i = 1;i <= n;i ++) {
        if (f[1] == f[0]) ans = ans * 2 % mod;
        if (cnt[f[1]] && cnt[f[0]]) {
            if (f[1] < f[0]) {
                cnt[f[1]] --;
                f[0] ++;
            } else {
                cnt[f[0]] --;
                f[1] ++;
            }
        } else if (cnt[f[1]]) {
            cnt[f[1]] --;
            f[0] ++;
        } else if (cnt[f[0]]) {
            cnt[f[0]] --;
            f[1] ++;
        } else {
            cout << 0 << '\n';
            return;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    while (T --) solve();
}