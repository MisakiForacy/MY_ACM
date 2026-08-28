#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 1005;

int dp[N][2];

int main() {
    int n;
    cin >> n;
    for (int i = 0;i < N;i ++) dp[i][0] = dp[i][1] = 1e8;
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1;i <= n;i ++) {
        int a, b, c;
        cin >> a >> b;
        c = a - b;
        dp[i][0] = dp[i - 1][0] + c;
        if (abs(dp[i - 1][1] + c) < abs(dp[i][0])) 
            dp[i][0] = dp[i - 1][1] + c;
        dp[i][1] = dp[i - 1][0] - c;
        if (abs(dp[i - 1][1] - c) < abs(dp[i][1]))
            dp[i][1] = dp[i - 1][1] - c;
    }
    cout << min(abs(dp[n][0]), abs(dp[n][1])) << '\n';
}