#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<LL> A(n + 1, 0), B(n + 1, 0), C(n + 1, 0), preB(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> A[i];
    for (int i = 1;i <= n;i ++) cin >> B[i];
    for (int i = 1;i <= n;i ++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    for (int i = 1;i <= n;i ++) {
        preB[i] = max(int(lower_bound(all(A), B[i]) - A.begin() - 1), 0);
        preB[i] += preB[i - 1];
    }
    LL Ans = 0;
    for (int i = 1;i <= n;i ++) {
        int it = max(int(lower_bound(all(B), C[i]) - B.begin() - 1), 0);
        Ans += preB[it];
    }
    cout << Ans << '\n';
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}