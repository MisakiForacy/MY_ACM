#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    int k;
    cin >> k;
    vector<LL> st(k + 2, 0), ed(k + 2, 0), v(k + 2, 0), a(k + 2, 0);
    string s, t;
    cin >> s >> t;
    s = "  " + s;
    t = "  " + t;
    for (int i = 2;i < siz(s);i ++) st[i] = s[i] - 'a';
    for (int i = 2;i < siz(t);i ++) ed[i] = t[i] - 'a';
    int c = 0, d = 0;
    for (int i = k + 1;i >= 2;i --) {
        v[i] = st[i] + ed[i] + c;
        c = v[i] / 26;
        v[i] %= 26;
    }
    if (c) v[1] = c, d = 1;
    c = 0;
    for (int i = (d ? 1 : 2);i <= k + 1;i ++) {
        a[i] = (c * 26 + v[i]) / 2;
        c = (c * 26 + v[i]) % 2;
    }
    for (int i = (a[1] > 1 ? 1 : 2);i <= k + 1;i ++) cout << char(a[i] + 'a');
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}