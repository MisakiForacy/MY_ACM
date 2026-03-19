#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i].x, a[i].y = i;
    sort(all(a), [&](pair<int, int> x, pair<int, int> y) {
        return x.x < y.x;
    });
    cout << a[1].y << ' ' << a[2].y << ' ' << a[3].y << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}