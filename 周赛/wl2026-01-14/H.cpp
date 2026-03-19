#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    LL n, S;
    cin >> n >> S;
    vector<PII> a(n + 1);
    LL Sm = 0;
    for (int i = 1;i <= n;i ++) cin >> a[i].x, a[i].y = i, Sm += a[i].x;
    LL Mx = (1 + n) * n / 2 * n + Sm;
    if (Mx <= S) {
        cout << n << ' ' << Mx << '\n';
    } else {
        auto check = [&](LL x) -> LL {
            LL k = x;
            sort(a.begin() + 1, a.end(), [&](PII x, PII y) {
                return x.x + x.y * k < y.x + y.y * k;
            });
            LL Sm = 0;
            for (int i = 1;i <= k;i ++) {
                Sm += a[i].x + a[i].y * k;
            }
            return Sm > S;
        };
        LL K = 0;
        for (int j = 20;j >= 0;j --) {
            LL Tp = K + (1LL << j);
            if (Tp > n || check(Tp)) continue;
            K = Tp;
        }
        LL Sm = 0;
        sort(a.begin() + 1, a.end(), [&](PII x, PII y) {
            return x.x + x.y * K < y.x + y.y * K;
        });
        for (int i = 1;i <= K;i ++) Sm += a[i].x + a[i].y * K;
        cout << K << ' ' << Sm << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}