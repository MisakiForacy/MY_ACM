#include <bits/stdc++.h>

#define x first 
#define y second

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve(int n) {
    vector<int> P;
    for (int i = 1;i <= n;i ++) P.push_back(i);
    LL ans = 0;
    do {
        int ok = 1;
        for (int i = 0;i < n;i ++) {
            for (int j = i;j < n;j ++) {
                if (P[i] * P[j] > (i + 1) * (j + 1) + n) ok = 0;
            }
        }
        ans += ok;
    } while (next_permutation(all(P)));
    cout << "n = " << n << ", ans = " << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
//     cin >> T;
    // while (T --) solve();
    for (int i = 1;i <= 10;i ++) solve(i);
}