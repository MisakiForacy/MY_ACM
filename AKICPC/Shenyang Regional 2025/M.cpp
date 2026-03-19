#include <bits/stdc++.h>
using namespace std;
using LL = long long;

#define lc pp << 1
#define rc pp << 1 | 1

void solve () {
    vector<LL> a(9), b(9), p(9);
    for (int i = 1;i <= 8;i ++) cin >> a[i] >> b[i];
    for (int i = 1;i <= 8;i ++) p[i] = i;
    double Max = 0;
    do {
        vector <vector<double>> dp (40, vector<double> (9, 0)); 
        auto dfs = [&](auto dfs, int pp, int l, int r) -> void {
            if (l == r) {
                dp[pp][p[l]] = 1;
                return;
            }
            int mid = l + r >> 1;
            dfs (dfs, lc, l, mid);
            dfs (dfs, rc, mid + 1, r);
            for (int i = 1;i <= 8;i ++) {
                for (int j = 1;j <= 8;j ++) {
                    if (i == j) continue;
                    dp[pp][i] += dp[lc][i] * dp[rc][j] * 1.0 * a[i] / (a[i] + b[j]);
                    dp[pp][j] += dp[lc][i] * dp[rc][j] * 1.0 * b[j] / (a[i] + b[j]);
                }
            }
        };
        dfs (dfs, 1, 1, 8);
        Max = max(Max, dp[1][1]);
    } while (next_permutation (p.begin() + 1, p.end()));
    cout << Max << '\n';
}

int main () {
    cout << fixed << setprecision(9);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T --) solve ();
}

/*
10 80
20 70
30 60
40 50
50 40
60 30
70 20
80 10
*/