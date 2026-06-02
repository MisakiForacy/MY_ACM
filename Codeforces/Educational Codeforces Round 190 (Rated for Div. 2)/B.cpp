#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e15;

void solve() {
    string s;
    cin >> s;
    LL ans = 0, add = 0;
    int n = siz(s);
    s = ' ' + s;
    vector<LL> p(n + 1, 0), ss(n + 2, 0);
    for (int i = 1;i <= n;i ++) {
        if ((s[i] - '0') % 2) {
            p[i] = p[i - 1] + 1;
        } else {
            p[i] = p[i - 1];
        }
    }
    for (int i = n;i >= 1;i --) {
        if ((s[i] - '0') % 2 == 0 && (s[i] - '0') % 4 != 0) {
            ss[i] = ss[i + 1] + 1;
        } else {
            ss[i] = ss[i + 1];
            if ((s[i] - '0') % 4 == 0) add ++;
        }
    }
    ans = inf;
    for (int i = 1;i <= n;i ++) {
        ans = min(ans, p[i - 1] + ss[i + 1]);
    }
    cout << ans + add << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}