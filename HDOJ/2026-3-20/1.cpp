#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> f(n + 1, vector<int> (4, 0));
    LL ans = 0;
    f[1][1] = 1;
    for (int i = 2;i <= n;i ++) {
        f[i][1] = f[i - 1][2] + f[i - 1][3];
        f[i][2] = f[i - 1][1] + f[i - 1][3];
        f[i][3] = f[i - 1][2] + f[i - 1][1];
    }
    ans += f[n][2] + f[n][3];
    cout << ans * 3 << '\n';
}