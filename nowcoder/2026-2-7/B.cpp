#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int N = 1e5 + 5;

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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<vector<int>> Mp(200);
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j < 200;j ++) {
            if (a[i] % P[j] == 0) {
                Mp[j].push_back(a[i]);
            }
        }
    }
    for (auto v : Mp) {
        if (siz(v) > 1) {
            cout << v[0] << ' ' << v[1] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
}

int main() {
    Euler();
    // cout << siz(P) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}