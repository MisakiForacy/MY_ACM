#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;
using LL = long long;

const LL inf = 1e15;

const int N = 6001;

int dp[N][N], Mi[N][N], Mx[N][N], use[N][N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);
    // vector<vector<int>> dp(n + 1, vector<int> (n + 1, 1));
    // vector<vector<int>> Mi(n + 2, vector<int>(n + 2));
    // vector<vector<int>> Mx(n + 2, vector<int>(n + 2));
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int l = 1;l <= n;l ++) {
        vector<int> p(n + 1, 0);
        int d = 0;
        Mi[l][l] = Mx[l][l] = a[l];
        for (int r = l;r <= n;r ++) {
            if (p[a[r]] ++ == 0) d ++;
            dp[l][r] = d;
            if (r == l) continue;
            Mi[l][r] = min(Mi[l][r - 1], a[r]);
            Mx[l][r] = max(Mx[l][r - 1], a[r]);
        }
    }
    // vector<vector<int>> use(n + 1, vector<int> (n + 1, 0));
    for (int l = 1;l <= n;l ++) {
        for (int r = l;r <= min(n, l + n / 2);r ++) {
            if (dp[l][r] == r - l + 1 && Mx[l][r] - Mi[l][r] == r - l) {
                use[r - l + 1][Mi[l][r]] = 1;
            }
        }
    }
    for (int i = n / 2;i >= 1;i --) {
        for (int j = 1;j <= n - i;j ++) {
            if (use[i][j] && use[i][j + i]) {
                cout << i << '\n';
                for (int i = 0;i <= n;i ++) {
                    for (int j = 0;j <= n;j ++) {
                        dp[i][j] = Mi[i][j] = Mx[i][j] = use[i][j] = 0;
                    }
                }
                return; 
            }
        }
    }
    cout << 0 << '\n';
    for (int i = 0;i <= n;i ++) {
        for (int j = 0;j <= n;j ++) {
            dp[i][j] = Mi[i][j] = Mx[i][j] = use[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
