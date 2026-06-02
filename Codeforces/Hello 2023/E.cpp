#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    string s;
    for (int i = 1;i <= n;i ++) s += '1';
    auto ask = [&](int i, string t) -> int {
        cout << "? " << i << ' ' << t << '\n';
        int x;
        cin >> x;
        return x;
    };
    for (int i = 1;i <= n;i ++) {
        string t = s;
        p[i - 1].y = i;
        t[i - 1] = '0';
        p[i - 1].x = ask(i, t);
    }
    sort(all(p), greater());
    s = "";
    for (int i = 1;i <= n;i ++) s += '0';
    s[p[0].y - 1] = '1';
    for (int i = 1;i < n;i ++)
        s[p[i].y - 1] = (ask(p[i].y, s) ? '1' : '0');
    cout << "! " << s << '\n';
}

int main() {
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
