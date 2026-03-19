#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n, x;
    cin >> n;
    map<int, int> mp;
    for (int i = 1;i <= n * n;i ++) {
        cin >> x;
        mp[x] ++;
    }
    int mx = 0;
    for (auto [k, v] : mp) mx = max(mx, v);
    cout << (mx <= (n - 1) * n ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}