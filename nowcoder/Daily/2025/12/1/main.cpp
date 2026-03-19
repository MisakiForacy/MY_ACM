#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    map<int, int> mp;
    for (int i = 1;i <= n;i ++) {
        mp[a[i] % k] ++;
    }
    int Mx = 0;
    for (auto [k, v] : mp) Mx = max(Mx, v);

    cout << Mx << '\n';
}