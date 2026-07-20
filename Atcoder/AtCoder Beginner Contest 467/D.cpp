#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    LL px, py, qx, qy, rx, ry, sx, sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
    LL dx1 = qx - px;
    LL dy1 = qy - py;
    LL dx2 = sx - rx;
    LL dy2 = sy - ry;
    if (dx1 * dy2 != dy1 * dx2) {
        cout << "Yes\n";
    } else {
        px *= 2, py *= 2, qx *= 2, qy *= 2, rx *= 2, ry *= 2, sx *= 2, sy *= 2;
        LL tx = (qx + px) / 2;
        LL ty = (qy + py) / 2;
        LL d1 = (tx - rx) * (tx - rx) + (ty - ry) * (ty - ry);
        LL d2 = (tx - sx) * (tx - sx) + (ty - sy) * (ty - sy);
        if (d1 == d2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}