#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve () {
    int n, l, r;
    cin >> n >> l >> r;
    vector<LL> a(n + 1), p(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    int L = 1, R = n;
    LL Ls = 0, Rs = 0;
    while (a[L] < l) {
        Ls += l - a[L];
        Rs += r - a[L];
        L ++;
    }
    while (a[R] > r) {
        Ls += a[R] - l;
        Rs += a[R] - r;
        R --;
    }
    cout << L << ' ' << R << '\n';
    while (L < R) {
        cout << L << ':' << a[L] << ", ";
        cout << R << ':' << a[R] << '\n';
        Ls -= a[L] - l;
        Ls += a[R] - l;
        Rs -= r - a[R];
        Rs += r - a[L];
        L ++, R --;
    }
    cout << min(Ls, Rs) << '\n';
}

/*
5 6 10
9 3 1 7 5

1 3 5   7 9   
      6     10

5 3 1   0 0
9 7 5   0 0
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}