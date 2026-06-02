#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n % 2 == 1) {
        cout << "YES\n";
    } else {
        if (count(all(s), '1') % 2 == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}