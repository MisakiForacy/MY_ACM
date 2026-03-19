#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

// int m = 99;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    int m = 0;
    for (int i = 0;i < n;i ++) cin >> a[i], m = max(m, siz(a[i]));
    for (int i = 0;i < n;i ++) {
        int use = (m - siz(a[i])) / 2;
        for (int j = 0;j < use;j ++) cout << '.';
        cout << a[i];
        for (int j = 0;j < use;j ++) cout << '.';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}