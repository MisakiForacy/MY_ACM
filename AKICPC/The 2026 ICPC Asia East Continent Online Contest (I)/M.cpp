#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    for (int i = 1;i <= n;i ++) {
        string s;
        cin >> s;
        mp[s] ++;
    }
    for (int i = 1;i <= m;i ++) {
        string s;
        cin >> s;
        if (mp[s] == 1) {
            mp[s] ++;
            cout << "OK\n";
        } else if (mp[s] == 0) {
            cout << "WRONG\n";
        } else {
            cout << "REPEAT\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}