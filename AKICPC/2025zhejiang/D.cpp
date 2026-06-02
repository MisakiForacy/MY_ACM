#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    vector<int> c(n + 2, 0);
    for (int i = 0;i <= n;i ++) cin >> c[i];
    for (int i = 0;i < n;i ++) {
        while (c[i] > 1) {
            s.push_back('R');
            c[i + 1] --;
            s.push_back('L');
            c[i] --;
        }
        s.push_back('R');
        c[i + 1] --;
        if (c[i] <= 0) {
            cout << "Impossible\n";
            return;
        }
    }
    if (c[n] != 0) {
        cout << "Impossible\n";
        return;
    }
    for (int i = n - 1;i >= 0;i --) {
        s.push_back('L');
        c[i] --;
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}