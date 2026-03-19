#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    sort(all(s));
    sort(all(t));
    cout << (s == t ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}