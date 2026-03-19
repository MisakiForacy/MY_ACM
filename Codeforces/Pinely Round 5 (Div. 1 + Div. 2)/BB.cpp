#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define LOG 20

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve () {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2, vector<int> (n + 2, 0));
    LL mins = inf, maxs = - inf, minp = inf, maxp = - inf;
    int cnt = 0;
    for (LL i = 1;i <= n;i ++) {
        for (LL j = 1;j <= n;j ++) {
            char c; cin >> c;
            a[i][j] = c == '#';
            if (c == '#') {
                mins = min(mins, i + j);
                maxs = max(maxs, i + j);
                minp = min(minp, i - j);
                maxp = max(maxp, i - j);
                cnt ++;
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == cnt) {
                cout << "YES\n";
                return;
            }
        }
    }
    if (maxs - mins <= 1 || maxp - minp <= 1) {
        cout << "YES\n";
        return;
    } else {
        cout << "NO\n";
    }
}

int main () {
    // freopen ("in", "r", stdin);
    // freopen ("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}