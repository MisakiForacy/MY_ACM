#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second
using namespace std;
using LL = long long;

mt19937_64 rng(time(0));

const int N = 2e5 + 10;
const LL inf = 1e15 + 10;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n + 1, 0), L(n + 1, -inf), R(n + 1, inf);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL ans = 0, ok = 1;
    while (q --) {
        LL p, l, r;
        cin >> p >> l >> r;
        L[p] = max(L[p], l);
        R[p] = min(R[p], r);
        if (L[p] > R[p]) {
            // return;
            ok = 0;
        }
        if (a[p] < L[p]) ans += L[p] - a[p], a[p] = L[p];
        if (a[p] > R[p]) ans += a[p] - R[p], a[p] = R[p];
    }
    if (!ok) {
        cout << -1 << '\n';
        return;
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