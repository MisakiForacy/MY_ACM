#include <bits/stdc++.h>

#define x first 
#define y second 

// #define double long double

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int N = 1e5 + 5;
const double eps = 1e-12;

vector<int> P, S(N, 0);

void Euler() {
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i);
        for (int j = 0;j < siz(P) && P[j] * i < N;j ++) {
            S[P[j] * i] = 1;
            if (i % P[j] == 0) break;
        }
    }
}

void solve() {
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double C = x1 * y2 - x2 * y1;
    double dy = y1 - y2;
    if (fabs(dy) < eps) {
        if (fabs(fabs(C) - 4.0) < eps) {
            cout << 0 << '\n';
        } else {
            cout << "no answer\n";
        }
        return;
    }
    double x3 = ( 4.0 - C) / dy;
    double x4 = (-4.0 - C) / dy;
    if (x3 == 0) {
        cout << x4 << '\n';
    } else {
        cout << x3 << '\n';
    }
}

int main() {
    // Euler();
    // cout << siz(P) << '\n';
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}