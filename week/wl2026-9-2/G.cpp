#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

LL s[4];

void solve() {
    int n, x;
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        cin >> x;
        s[i % 3] += x;
    }
    int mx = max({s[1], s[2], s[0]});
    if (s[1] == mx) cout << "chest\n";
    if (s[2] == mx) cout << "biceps\n";
    if (s[0] == mx) cout << "back\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}