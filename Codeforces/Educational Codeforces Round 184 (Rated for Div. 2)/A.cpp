#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

void solve () {
    int n, a;
    cin >> n >> a;
    vector<LL> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i];
    sort(all(p));
    int ans1 = 0, ans2 = 0;
    int b1 = a - 1, b2 = a + 1;
    for (int i = 0;i < n;i ++) {
        if (p[i] <= b1) ans1 ++;
        if (p[i] >= b2) ans2 ++;
    }
    if (ans1 >= ans2) cout << b1 << '\n';
    else cout << b2 << '\n';
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}