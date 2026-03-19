#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s + ' ';
    // cout << s << '\n';
    int Mx = 0;
    for (int i = 1;i <= n;i ++) {
        int len = s[i] == '0';
        while (s[i] == s[i + 1] && s[i] == '0') {
            i ++;
            len ++;
        }
        Mx = max(Mx, len);
    }
    if (s[1] == s[n] && s[1] == '0') {
        int L = 0, p = 1, R = 0;
        while (s[p] == '0') p ++, L ++;
        p = n;
        while (s[p] == '0') p --, R ++;
        Mx = max(Mx, L + R);
    }
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}