#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    string s;
    cin >> s;
    int n = s.length();
    s = ' ' + s;
    int cnt = 0;
    for (int i = 1;i <= n;i ++) {
        if (s[i] - s[i - 1] == 1) {
            int l = i - 1, r = i;
            while (s[r] - s[l] == 1) {
                l --, r ++;
                cnt ++;
            }
            i = r;
        }
    }
    cout << cnt << '\n';
}

int main () {
    int T = 1;
    cin >> T;
    while (T --) solve ();
}