#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0;i < n;i ++) {
        int n;
        cin >> n;
        for (int j = 0;j < n;j ++) {
            char c;
            cin >> c;
            if (c == 'U') a[i] --;
            if (c == 'D') a[i] ++;
            if (a[i] < 0) a[i] += 10;
        } 
        a[i] %= 10;
    }
    for (int x : a) cout << x << ' ';
    cout << '\n';
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
