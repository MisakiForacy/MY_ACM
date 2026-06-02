#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {  
    LL n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<LL> p(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '1')
            p[i] = p[i - 1] - 1;
        else 
            p[i] = p[i - 1] + 1;
    }
    for (int i = 0;i <= n;i ++) {
        if (p[i] == x && p[n] == 0) {
            cout << -1 << '\n';
            return;
        }
    } 
    if (p[n] == 0) {
        cout << 0 << '\n';
        return;
    }
    LL k = max(0LL, abs(x) / abs(p[n]) - 5);
    LL _1 = count(all(s), '1'); 
    LL _0 = count(all(s), '0');
    LL _1_ = _1 * k; 
    LL _0_ = _0 * k;
    LL ans = _0_ - _1_;
    LL val = 0;
    if (ans == x) val ++; 
    // cout << k << '\n';
    for (int t = 0;t < 10;t ++) {
        for (int i = 1;i <= n;i ++) {
            if (s[i] == '0') 
                ans += 1;
            else 
                ans -= 1;
            if (ans == x) val ++;
        }
    } 
    cout << val << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}