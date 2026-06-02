#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n, k, x;
    cin >> n >> k;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    cin >> x;
    int pp = 0, l = 0, r = 0;
    for (int i = 1;i <= x;i ++) {
        if ((a[i] ^ pp) != a[x]) {
            pp ^= 1;
            l ++;
        }
    }
    pp = 0;
    for (int i = n;i >= x;i --) {
        if ((a[i] ^ pp) != a[x]) {
            pp ^= 1;
            r ++;
        }
    }
    cout << max(l, r) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}