#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int f(int n, int m) {
    if (n == 1) return 1;
    return (f(n - 1, m) + m - 1) % n + 1;
}

int ff(int n, int m) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2;i <= n;i ++) 
        dp[i] = (dp[i - 1] + m - 1) % i + 1;
    return dp[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << f(n, m) << '\n';
    cout << ff(n, m) << '\n';
}