#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    LL Sum = 0;
    for (int i = 1;i <= n;i ++) cin >> a[i], Sum += a[i];
    sort(all(a));
    for (int i = 1;i <= n;i ++) {
        if (a[i] && Sum - (n - i + 1) >= n - 1) {
            cout << n - i + 1 << '\n';
            return;
        }
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}