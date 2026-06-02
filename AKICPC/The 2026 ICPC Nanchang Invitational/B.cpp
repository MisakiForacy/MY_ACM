#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, char>> p(4 * n);
    for (int i = 0;i < 4 * n;i ++)
        cin >> p[i].x >> p[i].y;
    int cnt = 5 * n;    
    map<char, int> ch;
    ch['R'] = 1, ch['Y'] = 2, ch['G'] = 3, ch['B'] = 4;
    while (cnt --) {
        for (int i = 1;i < 4 * n;i ++) {
            if (p[i].x == p[i - 1].x || p[i].y == p[i - 1].y) {
                if (ch[p[i - 1].y] > ch[p[i].y]) {
                    swap(p[i], p[i - 1]);
                } else if (p[i - 1].x > p[i].x) {
                    swap(p[i], p[i - 1]);
                }
            }
        }
    }
    int ok = 1;
    for (int i = 1;i < 4 * n;i ++) {
        if (ch[p[i - 1].y] > ch[p[i].y]) ok = 0;
        if (p[i - 1].y == p[i].y && p[i - 1].x > p[i].x) ok = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T = 1;
    cin >> T;
    while (T --) solve();
}

// 1 R
// 2 Y
// 2 R
// 1 G
// 1 Y
// 2 B
// 2 G
// 1 B