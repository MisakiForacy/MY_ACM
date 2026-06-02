#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    vector<array<double, 3>> p(8);
    vector<int> id(8);
    for (int i = 0;i < 8;i ++) cin >> p[i][0] >> p[i][1] >> p[i][2];
    for (int i = 0;i < 8;i ++) id[i] = i;
    auto dir = [&](array<double, 3> x, array<double, 3> y) -> double {
        return sqrt((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]) + (x[2] - y[2]) * (x[2] - y[2]));
    };
    do {
        vector<array<double, 3>> pp(8);
        for (int i = 0;i < 8;i ++) pp[i] = p[id[i]];
        double d1 = dir(pp[0], pp[1]), d2 = dir(pp[0], pp[2]);
        int ok = 1;
        if (!d1 || !d2) ok = 0;
        if (dir(pp[1], pp[2]) != d1) ok = 0;
        if (dir(pp[2], pp[3]) != d1) ok = 0;
        if (dir(pp[3], pp[0]) != d1) ok = 0;
        if (dir(pp[4], pp[5]) != d1) ok = 0;
        if (dir(pp[5], pp[6]) != d1) ok = 0;
        if (dir(pp[6], pp[7]) != d1) ok = 0;
        if (dir(pp[7], pp[4]) != d1) ok = 0;
        if (dir(pp[0], pp[5]) != d1) ok = 0;
        if (dir(pp[1], pp[6]) != d1) ok = 0;
        if (dir(pp[2], pp[7]) != d1) ok = 0;
        if (dir(pp[3], pp[4]) != d1) ok = 0;
        if (dir(pp[1], pp[3]) != d2) ok = 0;
        if (dir(pp[0], pp[4]) != d2) ok = 0;
        if (dir(pp[3], pp[5]) != d2) ok = 0;
        if (dir(pp[2], pp[4]) != d2) ok = 0;
        if (dir(pp[3], pp[7]) != d2) ok = 0;
        if (ok) {
            cout << "YES\n";
            return;
        }
    } while (next_permutation(all(id)));
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}