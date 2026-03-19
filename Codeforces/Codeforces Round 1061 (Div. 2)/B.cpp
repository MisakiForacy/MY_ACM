#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    LL a;
    int ok = 1;
    for (int i = 0;i < siz(s);i ++) 
        if (s[i] == 'B') 
            ok = 0;
    for (int i = 1;i <= q;i ++) {
        cin >> a;
        if (ok) {
            cout << a << '\n';
            continue;
        }
        int p = 0, ans = 0;
        while (a) {
            if (s[p] == 'A') a -= 1;
            else a /= 2;
            p ++;
            p %= n;
            ans ++;
        }
        cout << ans << '\n';
    }
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}