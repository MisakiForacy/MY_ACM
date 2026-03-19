#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), v(n + 1, inf);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) v[i] = min(v[i - 1], a[i]);
    int cur = 0;
    for (int i = n;i >= 1;i --) {
        if (cur + 1 <= a[i]) cur ++;
    }
    cout << cur + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}