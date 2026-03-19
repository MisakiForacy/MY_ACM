#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;

void solve() {
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(all(a));
    cout << (a[0] == a[3] ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}