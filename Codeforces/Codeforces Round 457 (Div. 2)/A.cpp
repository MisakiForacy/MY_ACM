#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

using PII = pair<LL, LL>;

void solve() {
    LL x, hh, mm;
    cin >> x >> hh >> mm;
    auto cal = [&](int h, int m) -> int {
        LL ret = h * 60 + m;
        ret %= 1440;
        return ret;
    };
    auto back = [&](int x) -> PII {
        x = (x + 1440) % 1440;
        return {x / 60, x % 60};
    };
    int s = cal(hh, mm);
    for (int y = 0;y <= 2000;y ++) {
        PII v = back(s - y * x);
        int xx = v.x, yy = v.y;
        while (xx) {
            if (xx % 10 == 7) {
                cout << y << '\n';
                return;
            }
            xx /= 10;
        }
        while (yy) {
            if (yy % 10 == 7) {
                cout << y << '\n';
                return;
            }
            yy /= 10;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}