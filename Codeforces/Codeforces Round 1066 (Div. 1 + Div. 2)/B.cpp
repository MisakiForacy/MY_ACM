#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve () {
    LL n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s; s = ' ' + s;
    int _4 = 0, _8 = 0;
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '4') _4 ++;
        if (s[i] == '8') _8 ++;
    }
    LL X[4], Y[4];
    X[0] = -n, Y[0] =  n;
    X[1] =  n, Y[1] =  n;
    X[2] = -n, Y[2] = -n;
    X[3] =  n, Y[3] = -n;
    LL Min = 40 * n;
    for (int i = 0;i < 4;i ++) Min = min(Min, abs(x - X[i]) + abs(y - Y[i]));
    if (abs(x) > abs(n) || abs(y) > abs(n) || Min < _4) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}