#include <bits/stdc++.h>

#define x first 

#define y second

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<LL> p;
    LL ans = 0, pre1 = 0, pre0 = 0;
    for (int i = 0;i < n;) {
        int len = 0, j = i - 1;
        while (j + 1 < n && s[j + 1] == s[i]) {
            j ++;
            len ++;
            ans += len / 2 + 1;
            if (len % 2 == 1) ans += pre0;
            if (len % 2 == 0) ans += pre1;
        }
        if (len % 2 == 0) {
            pre1 = len / 2 + 1;
            pre0 += len / 2;
        } else {
            pre1 += len / 2 + 1;
            pre0 = len / 2;
        }
        cout << i << ' ' << ans << '\n';
        i = j + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}