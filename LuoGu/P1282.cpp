#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 1005;

int dp[N][2];

int main() {
    int n;
    cin >> n;
    for (int i = 0;i < N;i ++) dp[i][0] = dp[i][1] = 1e8;
    dp[0] = 0, ;
    for (int i = 1;i <= n;i ++) {
        int a, b, c;
        cin >> a >> b;
        c = a - b;
        dp[i] = dp[i - 1]
    }
}