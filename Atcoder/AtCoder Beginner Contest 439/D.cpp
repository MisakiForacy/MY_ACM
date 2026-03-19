#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 1e7;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    map<LL, LL> mp3, mp7;
    LL Sm = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] % 3 == 0) mp3[a[i] / 3] ++;
        if (a[i] % 7 == 0) mp7[a[i] / 7] ++;
        if (a[i] % 5 == 0) Sm += mp3[a[i] / 5] * mp7[a[i] / 5];
    }
    mp3.clear(), mp7.clear();
    for (int i = n;i >= 1;i --) {
        if (a[i] % 3 == 0) mp3[a[i] / 3] ++;
        if (a[i] % 7 == 0) mp7[a[i] / 7] ++;
        if (a[i] % 5 == 0) Sm += mp3[a[i] / 5] * mp7[a[i] / 5];
    }
    cout << Sm << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}