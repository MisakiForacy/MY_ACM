#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const int N = 2e5 + 50;

void solve() {
    int n, Xor = 0;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i], c[i] = a[i] ^ b[i];
    for (int i = 1;i <= n;i ++) Xor ^= a[i];
    int cur = 1;
    vector<LL> base(31, 0), mask(31, 0), use(64);
    auto insert = [&](LL x, int idx) -> void {
        LL p = 1LL << cur;
        for (int j = 30;j >= 0;j --) {
            if (x >> j & 1) {
                if (!base[j]) {
                    base[j] = x;
                    mask[j] = p;
                    use[cur ++] = idx;
                    break;
                }
                x ^= base[j];
                p ^= mask[j];
            }
        }
    };
    for (int i = 1;i <= n;i ++) insert(c[i], i);
    LL pick = 0;
    for (int j = 30;j >= 0;j --) {
        if (Xor >> j & 1) {
            if (!base[j]) {
                cout << -1 << '\n';
                return;
            }
            Xor ^= base[j];
            pick ^= mask[j];
        }
    }
    for (int i = 1;i < cur;i ++) if (pick >> i & 1) {
        a[use[i]] = b[use[i]];
    }
    for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
