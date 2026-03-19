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
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    map<LL, int> mp;
    LL ans = 1;
    // for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
    // cout << '\n'; 
    for (int i = 1;i <= n;i ++) mp[a[i]] = i;
    for (int i = 1;i <= n;i ++) {
        LL mid = 2 * a[i];
        for (int j = 1;j <= i;j ++) {
            if (mp.count(mid - a[j])) {
                int L = j, R = mp[mid - a[j]];
                LL x = i - L, y = R - i;
                // cout << i << ' ' << L << ' ' << R << ' ' << x << ' ' << y << '\n';
                if (y > x) {
                    ans = max(ans, 2 * (x + 1));
                } else {
                    ans = max(ans, 2 * y + 1);
                }
                break;
            }
        }
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