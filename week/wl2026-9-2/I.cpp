#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    set<int> p[n + 1];
    int a[n + 1], mx = 0, t;
    map<set<int>, int> mp;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        for (int j = 1;j <= a[i];j ++) 
            cin >> t, p[i].insert(t);
        mp[p[i]] ++;
    }
    for (int i = 1;i <= n;i ++) {
        if (a[i] >= mx) {
            cout << "NO\n";
        } else {
            if (mp[p[i]] > 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}