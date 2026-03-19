#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve () {
    int n, x;
    cin >> n;
    map<int, int> mp;
    for (int i = 1;i <= n;i ++) {
        cin >> x;
        mp[x] ++;
    }
    int m = 0;
    for (auto [k, v] : mp) {
        m += (v >= k ? v - k : v);
    }
    cout << m << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}