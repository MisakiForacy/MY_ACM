#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(all(a));
    int p = 1;
    for (int i = 1;i <= n;i ++) {
        if (a[i] >= p) p ++;
    }
    cout << p << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}