#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int P = 13331;

void solve() {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s;
    t = s;
    reverse(all(t));
    s = ' ' + s;
    t = ' ' + t;
    vector<ULL> p(n + 2, 0);
    vector<ULL> h1(n + 2, 0), h2(n + 2, 0);
    p[0] = 1;
    for (int i = 1;i <= n;i ++){
        p[i] = p[i - 1] * P;
        h1[i] = h1[i - 1] * P + s[i];
        h2[i] = h2[i - 1] * P + t[i];
    }
    auto same = [&](int l, int r) -> int {
        ULL v1 = h1[r] - h1[l - 1] * p[r - l + 1];
        int rr = n - l + 1, ll = n - r + 1;
        // cout << ll << ' ' << rr << ' ';
        ULL v2 = h2[rr] - h2[ll - 1] * p[rr - ll + 1];
        // cout << v1 << ' ' << v2 << '\n';
        return (v1 == v2);
    };
    while (q --) {
        int l, r;
        cin >> l >> r;
        // cout << same(l, r) << '\n';
        if (same(l, r)) {
            cout << "Budada\n";
        } else if (same(l + 1, r) && same(l, r - 1)) {
            cout << "Budada\n";
        } else {
            if ((r - l + 1) & 1) {
                cout << "Putata\n";
            } else {    
                cout << "Budada\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}