#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

struct node
{
    int u, w;
    bool operator < (const node&T) const {
        return T.w < w;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    set<LL> p;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 2;i <= n;i ++) 
        if (abs(a[i] - a[i - 1]) != 1) 
            p.insert(abs(a[i] - a[i - 1]));
    if (siz(p) > 1) {
        cout << "NO\n";
    } else {
        int y, x = 1e9;
        if (siz(p)) y = *p.begin();
        else {
            cout << "YES\n";
            cout << x << ' ' << 1 << '\n';
            return;
        }
        if (y == 0) {
            cout << "NO\n";
            return;
        }
        // cout << y << '\n';
        for (int i = 2;i <= n;i ++) {
            if (y == 2 && abs(a[i] - a[i - 1]) == 1 && a[i] / 2 == a[i - 1] / 2) {
                cout << "NO\n";
                return;
            } else if (y != 2 && ((a[i] % y == 0 && a[i - 1] % y == 1) || (a[i - 1] % y == 0 && a[i] % y == 1))) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}