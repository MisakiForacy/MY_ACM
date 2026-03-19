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
    LL n;
    cin >> n;
    // vector<vector<int>> a(2,vector<int> (n + 1, 0));
    // int f = 1, x = 1, y = 0, p = 3, ans = 0;
    // while (x != n) {
    //     if (f) {
    //         if (!a[y][x + 1]) x += 1;
    //         else y ^= 1; 
    //         ans += 1;
    //     } else {
    //         if (p <= n) a[y][p] = 1;
    //         p += 2;
    //     }
    //     f ^= 1;
    // }
    // for (int i = 0;i < 2;i ++) {
    //     for (int j = 1;j <= n;j ++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << n / 5 + n - 1 << '\n';
}

int main() {
    // Euler();
    // cout << siz(P) << '\n';
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}