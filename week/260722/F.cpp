#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    LL ans = 0;
    for (char c = 'A';c <= 'Z';c ++) {
        if (count(s.begin(), s.end(), c)) {
            ans += count(s.begin(), s.end(), c) + 1;
        }
    }
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
