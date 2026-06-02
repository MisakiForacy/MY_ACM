#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    int A = 0, B = 0, Chg = 0;
    for (int i = 2;i <= n;i += 2) {
        A += (s[i - 1] == 'a');
        B += (s[i - 1] == 'b');
        A += (s[i] == 'a');
        B += (s[i] == 'b');
        if (A > B) s[i] = 'b', A --, B ++, Chg ++;
        if (B > A) s[i] = 'a', B --, A ++, Chg ++;
    }
    cout << Chg << '\n';
    cout << s.substr(1, n) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}