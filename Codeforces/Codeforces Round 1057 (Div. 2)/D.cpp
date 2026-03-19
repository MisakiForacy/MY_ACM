#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    int n;
    cin >> n;
    vector<LL> a(2 * n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) a[i + n] = a[i];
    vector<LL> dp(n + 5);
    LL ans = inf;
    for (int t = 1;t <= 3;t ++) {
        for (int i = 0;i < n + 5;i ++) dp[i] = inf;
        for (int i = 0;i < t;i ++) dp[i] = 0;
        for (int i = t;i <= n + t - 1;i ++) {
            if (i - t + 1 >= 2)
                dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 1]));
            if (i - t + 1 >= 3)
                dp[i] = min(dp[i], dp[i - 3] + max({
                    abs(a[i] - a[i - 1]), 
                    abs(a[i] - a[i - 2]), 
                    abs(a[i - 1] - a[i - 2])
                }));
        }
        ans = min(ans, dp[n + t - 1]);
    }
    cout << ans << '\n';
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}