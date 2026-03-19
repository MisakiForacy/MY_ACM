#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<int> dp = {-1}, idx;
    for (int i = 1;i <= n;i ++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (it == siz(dp)) {
            dp.push_back(a[i]);
        } else {
            dp[it] = a[i];
        }
    }
    for (int i = 1;i < siz(dp);i ++) cout << dp[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}