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
    if (count(all(s), '0') && count(all(s), '1')) {
        int cnt = 1;
        char s0 = s[0];
        for (int i = 1;i < n;i ++) {
            if (s[i] == s[i - 1]) cnt ++;
            else break;
        }
        if (count(all(s), s0) == cnt) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    } else {
        cout << 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
