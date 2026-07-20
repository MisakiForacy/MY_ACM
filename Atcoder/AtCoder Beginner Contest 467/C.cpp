#include <bits/stdc++.h>

using namespace std;

using LL = long long;

struct node {
    int a, b;
    string s;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1), b(n + 1);
    for (int i = n;i >= 1;i --) cin >> a[i];
    for (int i = n;i >= 2;i --) cin >> b[i];
    vector<vector<int>> f(2, vector<int> (n + 1));
    f[1][1] = !(a[1]);
    f[1][0] = a[1];
    for (int i = 2;i <= n;i ++) {
        f[i][1] = 
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
