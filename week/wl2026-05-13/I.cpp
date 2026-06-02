#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0;
    for (int j = 1;j < siz(s);j ++) {
        int ii = 0, jj = j, len = 0;
        while (ii < j && s[ii] == s[jj]) {
            len ++;
            ii ++;
            jj ++;
        }
        if (ii == j) mx = max(mx, len);
    }
    cout << min(n, n - mx + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}