#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define x first 

#define y second 

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

const int N = 24;

const LL inf = 1e15;

void solve() {
    LL m, r, c;
    cin >> m >> r >> c;
    int t = 0, p = 0, cnt = 0;
    LL mm = m;
    LL cd = 0, rd = 0, f1 = 0, f2 = 0; 
    // f1 = 1 表示进入幽灵形态， cd 就要持续减
    // f2 = 1 表示进入换弹， rd 就要持续减
    while (1) {
        if (mm == m && !f1 && !f2) cnt ++;
        cout << mm << ' ' << f1 << ' ' << f2 << '\n';
        if (cnt == 2) break;
        if (mm) {
            mm --;
            p ++;
            t ++;
        }
        if (cd) {
            cd --;
            if (!cd) f1 = 0;
        }
        if (!mm) {
            if (!f1) {
                f1 = 1;
                cd = c;
                mm = m;
            } else if (!f2) {
                f2 = 1;
                rd = r;
            } else if (rd) {
                rd --;
                t ++;
                if (!rd) {
                    mm = m;
                    f2 = 0;
                }
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << 1.0 * p / (1.0 * t) << '\n'; 
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
