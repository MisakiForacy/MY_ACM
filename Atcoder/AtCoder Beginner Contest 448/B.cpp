#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<LL> c(m + 1);
    for (int i = 1;i <= m;i ++) cin >> c[i];
    LL sm = 0;
    for (int i = 1;i <= n;i ++) {
        LL a, b;
        cin >> a >> b;
        if (b <= c[a]) {
            sm += b;
            c[a] -= b;
        } else {
            sm += c[a];
            c[a] = 0;
        }
    }
    cout << sm << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}