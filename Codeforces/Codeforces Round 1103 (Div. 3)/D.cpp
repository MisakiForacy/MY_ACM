#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(all(a));
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}