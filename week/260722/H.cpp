#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    LL s[26], t[26];
    memset(s, 0, sizeof s);
    memset(t, 0, sizeof t);
    for (int i = 1;i <= n;i ++) {
        int d, k;
        cin >> d >> k;
        string ss;
        cin >> ss;
        for (char c : ss)
            (d == 1 ? s[c - 'a'] : t[c - 'a']) += k;
        int ok = 0, f = 0, ok2 = 0;
        for (int j = 25;j >= 0;j --) {
            for (int k = j - 1;k >= 0;k --) {
                if (t[j] && s[k]) {
                    ok = 1;
                    break;
                }
            }
            if (ok) break;
        }
        // cout << ok << '\n';
        LL sum = 0;
        for (int j = 25;j >= 0;sum += s[j], j --) {
            if (s[j] < t[j]) ok = 1;
            else if (s[j] > t[j]) break;
        }
        // for (int j = 0;j <= 25;j ++) sum += s[j];
        if (!sum) ok = 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
