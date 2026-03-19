#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

const int N = 2e5 + 10;

void solve() {
    string s = "";
    int q, p = 1;
    cin >> q;
    vector<int> dp(q + 1, 0), Min(q + 1, 0);
    for (int i = 1;i <= q;i ++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            char c;
            cin >> c;
            p = p + 1;
            dp[p] = dp[p - 1] + (c == '(' ? 1 : -1);
            Min[p] = min(Min[p - 1], dp[p]);
        } else {
            p = p - 1;
        }
        // cout << p << ' ' << dp[p] << ' ' << Min[p] << '\n';
        cout << ((dp[p] == 0 && Min[p] >= 0) ? "Yes\n" : "No\n");
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}