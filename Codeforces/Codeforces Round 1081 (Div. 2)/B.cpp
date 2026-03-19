#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (count(all(s), '1') & 1) {
        if (count(all(s), '0') & 1) {
            cout << count(all(s), '0') << '\n';
            for (int i = 0;i < n;i ++) {
                if (s[i] == '0') {
                    cout << i + 1 << '\n';
                }
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    } else {
        cout << count(all(s), '1') << '\n';
        for (int i = 0;i < n;i ++) {
            if (s[i] == '1') {
                cout << i + 1 << ' ';
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}