#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for (char &c : s) if (c == 'G' || c == 'B') c = 'F';
    for (char &c : t) if (c == 'G' || c == 'B') c = 'F';
    cout << (s == t ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}