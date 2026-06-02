#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, mxx = 0;
    cin >> n;
    vector<string> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i];
    for (int i = 0;i < n;i ++) {
        for (int j = i + 1;j < n;j ++) {
            string s = p[i], t = p[j];
            int ls = siz(s), lt = siz(t);
            s = ' ' + s, t = ' ' + t;
            vector<vector<int>> dp(ls + 1, vector<int> (lt + 1, 0));
            int mx = 0;
            for (int ii = 1;ii <= ls;ii ++) {
                for (int jj = 1;jj <= lt;jj ++) {
                    if (s[ii] == t[jj]) {
                        dp[ii][jj] = dp[ii - 1][jj - 1] + 1;
                        mx = max(mx, dp[ii][jj]);
                    }
                }
            }
            mxx = max(mxx, mx);
        }
    }
    cout << mxx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}