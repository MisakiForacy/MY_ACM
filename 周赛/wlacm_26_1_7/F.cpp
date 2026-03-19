#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), b(n + 1, 0), alls, L(n + 1, n + 1), R(n + 1, 0), p(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], alls.push_back(a[i]);
    LL Ans = 1;
    sort(alls.begin(), alls.end());
    alls.erase(unique(all(alls)), alls.end());
    for (int i = 1;i <= n;i ++) 
        a[i] = lower_bound(all(alls), a[i]) - alls.begin() + 1;
    for (LL i = 1;i <= n;i ++) {
        L[a[i]] = min(L[a[i]], i);
        R[a[i]] = max(R[a[i]], i);
    }
    for (int i = 1;i <= n;i ++) {
        if (R[i]) {
            p[L[i]] ++, p[R[i] + 1] --; 
        } else break;
    }
    for (int i = 1;i <= n;i ++) p[i] += p[i - 1];
    for (int i = 1;i <= n;i ++) {
        if (R[i]) {
            if (p[L[i]] == p[R[i]] && i != a[1])
                Ans *= 2, Ans %= 998244353;
        } else break;
    }
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
