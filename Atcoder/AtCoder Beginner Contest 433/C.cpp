#include <bits/stdc++.h>
#define int long long
using namespace std;
using LL = long long;

void solve () {
    string s;
    cin >> s;
    int n = s.length();
    s = 'A' + s + 'Z';
    int cnt = 0;
    for (int i = 1;i <= n;i ++) {
        if (s[i] - s[i - 1] == 1) {
            int l = i - 1, r = i;
            while (s[r] - s[l] == 1 && s[l] == s[i - 1] && s[r] == s[i]) {
                l --, r ++;
                cnt ++;
            }
            i = r - 1;
        }
    }
    cout << cnt << '\n';
}

signed main () {
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}