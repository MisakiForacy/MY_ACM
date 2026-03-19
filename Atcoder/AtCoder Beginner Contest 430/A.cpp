#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

void solve () {
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = (c >= a) + (d < b);
    cout << (ans == 2 ? "Yes\n" : "No\n");
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}