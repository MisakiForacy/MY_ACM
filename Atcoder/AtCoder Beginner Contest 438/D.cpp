#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n;
    cin >> n;
    vector<LL> A(n + 1, 0), B(n + 1, 0), C(n + 1);
    vector<LL> Ap(n + 1, 0), Bp(n + 1, 0), Cp(n + 1), Mx(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> A[i], Ap[i] = Ap[i - 1] + A[i];
    for (int i = 1;i <= n;i ++) cin >> B[i], Bp[i] = Bp[i - 1] + B[i];
    for (int i = 1;i <= n;i ++) cin >> C[i], Cp[i] = Cp[i - 1] + C[i];
    for (int i = n - 1;i >= 2;i --) {
        LL Sm = Cp[n] - Cp[i] + Bp[i];
        Mx[i] = max(Mx[i + 1], Sm);
    }
    for (int i = 1;i < n - 1;i ++) {
        LL Sm = Ap[i] + Mx[i + 1] - Bp[i];
        Mx[0] = max(Mx[0], Sm);
    }
    cout << Mx[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}