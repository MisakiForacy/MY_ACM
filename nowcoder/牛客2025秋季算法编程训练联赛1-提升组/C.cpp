#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

const LL MOD = 1e9 + 7;

void solve() {
    LL n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<LL> dp(n + 1, 0);    
    auto get = [&](int l, int r) -> string {
        string t;
        for (int j = l;j <= r;j ++) t.push_back(s[j]);
        return t;
    };
    for (int i = 1;i <= n;i ++) {
        dp[i] = max(dp[i], dp[i - 1]);
        if (i >= 4 && get(i - 3, i) == "nico") {
            dp[i] = max(dp[i], dp[i - 3] + a);
        }
        if (i >= 6 && get(i - 5, i) == "niconi") {
            dp[i] = max(dp[i], dp[i - 5] + b);
        }
        if (i >= 10 && get(i - 9, i) == "niconiconi") {
            dp[i] = max(dp[i], dp[i - 9] + c);
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}