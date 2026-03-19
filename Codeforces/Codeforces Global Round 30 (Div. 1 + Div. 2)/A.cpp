#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5;
const LL inf = 1e15;

void solve () {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL x;
    cin >> x;
    int ok = 0;
    if (n == 1) {
        cout << (a[1] == x ? "YES\n" : "NO\n");
        return;
    }
    for (int i = 1;i < n;i ++) {
        if (a[i] <= x && a[i + 1] >= x) ok = 1;
        if (a[i] >= x && a[i + 1] <= x) ok = 1;
    }
    cout << (ok ? "YES\n" : "NO\n");
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