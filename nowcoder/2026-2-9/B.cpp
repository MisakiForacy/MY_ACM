#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
 
using namespace std;
using LL = long long;

void solve() {
    LL n, q, s;
    cin >> n >> q >> s;
    vector<LL> p(n + 2);
    for (int i = 1;i <= n;i ++) cin >> p[i];
    for (int i = 1;i <= n;i ++) p[i] += p[i - 1];
    while (q --) {
        int x, y;
        cin >> x >> y;
        cout << p[x - 1] + y - 1 + s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}