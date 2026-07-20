#include <bits/stdc++.h>

using namespace std;

using LL = long long;

struct node {
    int a, b;
    string s;
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n);
    for (int i = 0;i < n;i ++) {
        cin >> p[i].a >> p[i].b >> p[i].s;
    }
    LL ans = 0;
    LL x = 10000, y = 10000;
    for (int i = 0;i < n;i ++) {
        if (p[i].s == "keep") {
            x -= p[i].b;
        } else {
            x -= p[i].a;
        }
        y -= p[i].a;
    }
    cout << y - x << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
