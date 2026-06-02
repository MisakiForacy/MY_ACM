#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    LL a, ta, b, tb, h, m;
    char c;
    cin >> a >> ta >> b >> tb;
    cin >> h >> c >> m;
    a = a * 60, ta = ta * 60;
    b = b * 60, tb = tb * 60;
    LL st = h * 3600 + m * 60;
    LL k = 5 * 3600, kk = 24 * 3600 - 1;
    int cnt = 0;
    for (int i = k;i <= kk;i += b) {
        if ((i <= st && i + tb > st) || (i >= st && i < st + ta)) {
            cnt ++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}