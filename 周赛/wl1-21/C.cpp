#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    string s;
    cin >> s;
    int o = 0;
    for (char c : s) {
        if (!(c - '0' & 1)) {
            o ++;
        }
    }
    if (!o) {
        cout << -1 << '\n';
    } else {
        if (s.back() - '0' & 1) {
            if (s[0] - '0' & 1) {
                cout << 2 << '\n';
            } else {
                cout << 1 << '\n';
            }
        } else {
            cout << 0 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}