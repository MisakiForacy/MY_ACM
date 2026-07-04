#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    int cur = n;
    int l = 0, r = n - 1, f = 1;
    while (l <= r) {
        if (s[cur - 1] == 'o') f ^= 1;
        if (!f) p[l ++] = cur --;
        else    p[r --] = cur --;
    }
    for (int i = 0;i < n;i ++) cout << p[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
