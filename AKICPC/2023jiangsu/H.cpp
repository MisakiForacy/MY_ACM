#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> p(n + 1);
    s = ' ' + s;
    t = ' ' + t;
    for (int i = 1;i <= n;i ++) {
        p[i] = (t[i] - s[i] + 26) % 26;
    }
    int ok = 1, ans = 0;
    for (int i = 1;i <= n;i ++) {
        if (p[i]) ok = 0;
        if (!ok && p[i] != p[i - 1]) ans ++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}