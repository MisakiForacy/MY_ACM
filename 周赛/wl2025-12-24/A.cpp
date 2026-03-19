#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<LL> bad;
    LL Sm = 0;
    for (int i = 1;i <= n;i ++) {
        int Cur, Chg;
        if (s[i] == 'R') {
            Cur = n - i;
            Chg = i - 1;
        } else {
            Cur = i - 1;
            Chg = n - i;
        }
        Sm += Cur;
        if (Chg > Cur) bad.push_back(Chg - Cur);
        else           bad.push_back(0);
    }
    sort(bad.begin(), bad.end(), greater());
    for (int i = 0;i < n;i ++) {
        Sm += bad[i];
        cout << Sm << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}