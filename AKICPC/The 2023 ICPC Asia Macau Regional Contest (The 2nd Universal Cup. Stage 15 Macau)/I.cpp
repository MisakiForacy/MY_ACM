#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

void solve() {
    LL a, b, m;
    cin >> a >> b >> m;
    LL ans = 0;
    LL aa = 0, bb = 0;
    for (int i = 0;i <= m;i ++) {
        aa = max(0LL, aa - 1), bb = max(0LL, bb - 1);
        if (aa == 0 && bb == 0) {
            aa = a, bb = b;
            ans += 320;
        } else if (aa == 0) {
            aa = a;
            ans += 160;
        } else if (bb == 0) {
            if (aa > m - i) {
                aa = a, bb = b;
                ans += 160;
            } else if (aa < b) {
                continue;
            } else {
                aa = a, bb = b;
                ans += 160;
            }
        }
    }
    cout << ans << '\n';
}   

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("in.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
        // brute();
    }
}