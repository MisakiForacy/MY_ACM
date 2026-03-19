#include <bits/stdc++.h>

#define x first 
#define y second

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 2, 0), B(n + 2, 0), C(n + 2, 0), D(n + 2, 0), E(n + 2, 0);
    for (int i = 1;i <= n;i ++) {
        int x, y;
        cin >> x >> y;
        A[x] ++, B[y] ++;
        if (max(x, y) - min(x, y) == 1) C[max(x, y)] ++;
        if (max(x, y) - min(x, y) == 2) D[max(x, y)] ++;
        if (max(x, y) - min(x, y) == 0) E[max(x, y)] ++;
    }
    for (int i = 1;i <= n;i ++) A[i] += A[i - 1], B[i] += B[i - 1];
    for (int i = 1;i <= n;i ++) C[i] += C[i - 1], D[i] += D[i - 1], E[i] += E[i - 1];
    while (q --) {
        int x;
        cin >> x;
        int l = max(0, x - 2), r = x + 1;
        LL useA = A[r] - A[l], useB = B[r] - B[l];
        LL useC = C[r] - C[r - 2], useD = D[r] - D[r - 1], useE = E[r] - E[l];
        LL good = useA + useB - useC - useD - useE;
        cout << n - good << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}