#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    // LL s[26], t[26];
    // memset(s, 0, sizeof s);
    // memset(t, 0, sizeof t);
    vector<LL> s(26, 0), t(26, 0);
    s[0] = 1, t[0] = 1;
    for (int i = 1;i <= n;i ++) {
        LL d, k;
        cin >> d >> k;
        string ss;
        cin >> ss;
        for (char c : ss)
            if (d == 1)
                s[c - 'a'] += k;
            else
                t[c - 'a'] += k;
        int ok = 0;
        for (int j = 1;j <= 25;j ++) {
            if (!t[j]) continue;
            for (int k = 0;k < j;k ++) {
                if (s[k]) ok = 1;
            }
        }
        for (int j = 25;j >= 0;j --) {
            if (s[j] < t[j]) {ok = 1; break;}
            if (s[j] > t[j]) {break;}
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
