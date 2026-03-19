#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve () {
    int n, m;
    cin >> n >> m;
    map<int, double> mp;
    map<int, int> cnt;
    for (int i = 1;i <= n;i ++) {
        int A, B;
        cin >> A >> B;
        mp[A] += B;
        cnt[A] += 1;
    }
    for (auto [k, v] : mp) {
        cout << v / cnt[k] << '\n';
    }
}

int main () {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}