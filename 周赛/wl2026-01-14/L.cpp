#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), b1(2e5 + 1, 0), b2(2e5 + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    for (int i = 1;i <= n;i ++) {
        if (!b1[a[i]]) b1[a[i]] ++;
        else if (!b2[a[i]]) b2[a[i]] ++;
        else {
            cout << "NO\n";
            return;
        }
    }
    vector<int> x, y;
    for (int i = 0;i <= 2e5;i ++) {
        if (b1[i]) {
            b1[i] --;
            x.push_back(i);
        }
    }
    for (int i = 2e5;i >= 0;i --) {
        if (b2[i]) {
            b2[i] --;
            y.push_back(i);
        }
    }
    cout << "YES\n";
    cout << siz(x) << '\n';
    for (int v : x) cout << v << ' ';
    cout << '\n';
    cout << siz(y) << '\n';
    for (int v : y) cout << v << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}