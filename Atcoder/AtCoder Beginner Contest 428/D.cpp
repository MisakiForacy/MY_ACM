#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

const int N = 2e5 + 10;

LL qmi(LL a, LL k) {
    LL res = 1;
    while (k) {
        if (k & 1) res *= a;
        a *= a;
        k >>= 1;
    }
    return res;
}

LL isqrt(LL x) {
    LL cur = 0;
    for (int j = 31;j >= 0;j --) {
        LL val = cur + (1LL << j);
        if (val * val > x) continue;
        cur += 1LL << j;
    }
    return cur;
}

void solve() {
    LL x, n;
    cin >> x >> n;
    LL lo = log10(x) + 1, hi = log10(x + n) + 1;
    LL ans = 0, L, R;
    L = isqrt(x * qmi(10, lo) + x);
    R = isqrt(x * qmi(10, lo) + min(x + n, qmi(10, lo) - 1));
    ans += R - L;
    for (int i = lo + 1;i <= hi;i ++) {
        L = isqrt(x * qmi(10, i) + qmi(10, i - 1) - 1);
        R = isqrt(x * qmi(10, i) + min(x + n, qmi(10, i) - 1));
        ans += R - L;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}