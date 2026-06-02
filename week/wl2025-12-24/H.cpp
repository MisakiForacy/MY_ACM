#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, bad = 0;
    cin >> n;
    vector<LL> a(n + 1, 0), Mi(n + 2, 1000010);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = n;i >= 1;i --) Mi[i] = min(Mi[i + 1], a[i]);
    for (int i = 1;i <= n;i ++) if (a[i] > Mi[i]) bad ++;
    cout << bad << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}