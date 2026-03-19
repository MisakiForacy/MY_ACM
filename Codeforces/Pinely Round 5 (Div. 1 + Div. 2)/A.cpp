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

void solve () {
    LL r, x, d, n;
    cin >> r >> x >> d >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    int cnt = 0;
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '1') {
            r = max(r - d, 0LL);
            cnt ++;
        } else if (s[i] == '2' && r < x) {
            r = max(r - d, 0LL);
            cnt ++;
        }
    }
    cout << cnt << '\n';
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