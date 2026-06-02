#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const int yy1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int yy2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

vector<int> p(4000000, 0);

int dd[10000][13][32];

int run(int y) {
    if (y % 4 == 0 && y % 100 != 0) {
        return 1;
    } else if (y % 100 == 0 && y % 400 == 0) {
        return 1;
    }
    return 0;
}

void init() {
    LL Y = 2000, M = 1, D = 1, idx = 1;
    while (1) {
        int ok = 0;
        dd[Y][M][D] = idx;
        string s;
        s += Y / 1000 % 10 + '0';
        s += Y / 100 % 10 + '0';
        s += Y / 10 % 10 + '0';
        s += Y / 1 % 10 + '0';
        s += M / 10 % 10 + '0';
        s += M / 1 % 10 + '0';
        s += D / 10 % 10 + '0';
        s += D / 1 % 10 + '0';
        for (int i = 0;i <= siz(s) - 2;i ++) {
            if (s.substr(i, 3) == "202") {
                ok = 1;
                break;
            }
        }
        p[idx] = p[idx - 1] + ok;
        D ++;
        if (run(Y)) {
            if (D > yy2[M]) {
                D = 1;
                M ++;
                if (M > 12) {
                    M = 1;
                    Y ++;
                }
            }
        } else {
            if (D > yy1[M]) {
                D = 1;
                M ++;
                if (M > 12) {
                    M = 1;
                    Y ++;
                }
            }
        }
        if (Y == 10000) break;
        idx ++;
    }
}

void solve() {
    int Y1, M1, D1, Y2, M2, D2;
    cin >> Y1 >> M1 >> D1 >> Y2 >> M2 >> D2;
    int id1 = dd[Y1][M1][D1], id2 = dd[Y2][M2][D2];
    // cout << id1 << ' ' << id2 << '\n';
    cout << p[id2] - p[id1 - 1] << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}