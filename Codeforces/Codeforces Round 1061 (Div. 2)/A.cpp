#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

void solve() {
    LL n;
    cin >> n;
    LL ans = 0;
    while (n > 2) {
        ans += n / 3;
        n = n / 3 + n % 3;
    }
    cout << ans << '\n';
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}