#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e18;

// 4 2 3 1 5

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1, 0);
    f[0] = 1;
    int ans = 0;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (f[i - 1]) continue;
        if (a[i - 1] == 7 - a[i] || a[i - 1] == a[i]) f[i] = 1, ans ++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}