#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    string s;
    cin >> s;
    int n = siz(s);
    sort(s.begin() + 1, s.end());
    LL S = s[0] - '0';
    int c1 = 0, c2 = 1;
    for (int i = 1;i < n;i ++) {
        if (s[i] - '0' + S >= 10) {
            c1 ++;
        } else {
            S += s[i] - '0';
        }
    }
    S = 1;
    for (int i = 1;i < n;i ++) {
        if (s[i] - '0' + S >= 10) {
            c2 ++;
        } else {
            S += s[i] - '0';
        }
    }
    cout << min(c1, c2) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}