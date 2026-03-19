#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> Mp(n + 1, vector<int> (n + 1, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            char c; cin >> c;
            Mp[i][j] = c == '#';
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + Mp[i][j];
        }
    }
    vector<vector<int>> use(n + 1, vector<int> (n + 1, 0));
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            for (int k = 1;k <= n - max(i, j) + 1;k ++) {
                
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve(); 
}