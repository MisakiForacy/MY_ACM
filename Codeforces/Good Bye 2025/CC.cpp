#include <bits/stdc++.h>

#define x first 
#define y second 

#define LOG 30

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    LL X = 0;
    int n;
    cin >> n;
    vector<LL> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], b[i] = -a[i];
    vector<LL> A(n + 2, 0), B(n + 2, 0);
    for (int i = n;i >= 2;i --) B[i] = B[i + 1] + b[i];
    A[1] = a[1];
    for (int i = 2;i <= n;i ++) A[i] = A[i - 1] + abs(a[i]);
    LL Mx = B[2];
    for (int i = 2;i <= n;i ++) {
        LL Sm = A[i - 1] + B[i + 1];
        Mx = max(Mx, Sm);
    }
    cout << Mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}