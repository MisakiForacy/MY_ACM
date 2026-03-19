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
    LL n, X;
    cin >> n >> X;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    int l = 1, r = n;
    LL ans = 0;
    vector<int> p;
    LL use = X;
    while (l <= r) {
        if (a[r] >= use) {
            ans += a[r];
            use = use - a[r] + X;
            p.push_back(a[r]);
            r --;
        } else {
            if (a[l] >= use) {
                ans += a[l];
                use = use - a[l] + X;
            } else {
                use = use - a[l];
            }
            p.push_back(a[l]);
            l ++;
        }
    }
    cout << ans << '\n';
    for (int x : p) cout << x << ' ';
    cout << '\n';
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