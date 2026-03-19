#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n + 1);
    vector<vector<LL>> p(n + 1, vector<LL> (32, 0));
    LL x = 0;
    for (int i = 1;i <= n;i ++) cin >> a[i], x ^= a[i];
    while (q --) {
        LL b;
        cin >> b;

    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}