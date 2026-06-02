#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    string s;
    cin >> s;
    int n = siz(s);
    s = ' ' + s;
    vector<int> nxt0(n + 2, n + 1), nxt1(n + 2, n + 1);
    for (int i = n;i >= 1;i --) {
        if (s[i] == '0') {
            nxt0[i] = i;
            nxt1[i] = nxt1[i + 1];
        } else {
            nxt0[i] = nxt0[i + 1];
            nxt1[i] = i;
        }
    }
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '1') {
            ans += (n - nxt0[i] + 1) * 2;
        } else {
            ans += (n - nxt1[i] + 1) + (n - i + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}