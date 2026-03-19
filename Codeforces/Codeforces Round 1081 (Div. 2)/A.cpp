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
    int ans = 0;
    for (int i = 0;i < n;i ++) {
        ans += 1;
        int p = i;
        while (p < n && s[i] == s[p]) p ++;
        i = p - 1;
    }
    if (n == ans) cout << ans << '\n';
    else
    cout << (s[0] == s.back() ? ans : ans + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}