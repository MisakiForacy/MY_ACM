#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "  " + s;
    int ans = 0;
    for (int i = 2;i <= n + 1;i ++) {
        if (s[i] == '0' && s[i - 1] == '0') {
            ans += 2;
        } else if (s[i] == '0' && s[i - 2] == '0') {
            ans += 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}