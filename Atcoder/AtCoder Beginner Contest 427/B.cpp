#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second 
using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

mt19937_64 rng(time(0));

void solve() {
    LL n;
    cin >> n;
    auto f = [&](int x) -> LL {
        LL sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };
    LL ans = 0;
    vector<LL> a(n + 1, 0);
    a[1] = 1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j < i;j ++) {
            a[i] += f(a[j]);
        }
    }
    for (int i = 0;i <= n;i ++) ans += f(a[i]);
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        solve();
    }
}