#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

int isprime(int x) {
    if (x == 1) return 0;
    for (int i = 2;i <= sqrt(x);i ++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    vector<int> p;
    p.push_back(0);
    for (int i = 1;i <= 200;i ++) if (isprime(i)) p.push_back(i);
    while (cin >> n) {
        vector<vector<LL>> dp(n + 1, vector<LL>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j < siz(p) && p[j] <= i;j ++) {
                for (int k = 0;k < siz(p) && p[k] <= n;k ++) {
                    if (j >= k)
                    dp[i][p[j]] += dp[i - p[j]][p[k]];
                }
            }
        }
        LL ans = 0;
        for (int i = 0;i <= n;i ++) ans += dp[n][i];
        cout << ans << '\n';
    }
}