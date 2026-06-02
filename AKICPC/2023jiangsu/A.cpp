#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

int add = 1;

void solve() {
    int n, m, cnt = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    while (siz(s) / 2 < m) {
        string t;
        for (int i = 0;i < siz(s) / 2;i ++) t.push_back(s[i]);
        t += s;
        for (int i = siz(s) / 2;i < siz(s);i ++) {
            char nc = (s[i] - 'a' + 1) % 26 + 'a';
            t.push_back(nc);
        }
        s = t;
        cnt ++;
    } 
    add -= cnt;
    add += 26;
    add %= 26;
    string t;
    for (int i = siz(s) - 1;i >= siz(s) - m;i --) t = s[i] + t;
    // cout << t << '\n';
    // cout << siz(t) << '\n';
    for (int i = 0;i < m;i ++) {
        char nc = (t[i] - 'a' + add) % 26 + 'a';
        t[i] = nc;
    }
    cout << t << '\n';
}

// wrwxrwxsxy

int main() {
    for (int i = 1;i <= 100;i ++) {
        add *= 10;
        add %= 26;
    }
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}