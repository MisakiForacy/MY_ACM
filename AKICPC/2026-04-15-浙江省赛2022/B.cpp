#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    string s, t;
    cin >> s;
    for (int i = 0;i < siz(s);i ++) {
        t.push_back(s[i]);
        if (siz(t) >= 3 && t.substr(siz(t) - 3, 3) == "cjb") {
            t.push_back(',');
        }
    }
    cout << t << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}