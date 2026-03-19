#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;

mt19937_64 rnd(time(0));

void solve() {
    LL n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL sm = 0;
    for (int i = 1;i <= n;i ++) {
        sm += a[i] / x * y;
    }
    LL mx = 0;
    for (int i = 1;i <= n;i ++) {
        mx = max(mx, sm - a[i] / x * y + a[i]);
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}