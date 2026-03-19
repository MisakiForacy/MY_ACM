#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

void solve () {
    LL n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> A(n + 1, 0), B(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        A[i] = A[i - 1] + (s[i] == 'a');
        B[i] = B[i - 1] + (s[i] == 'b');
    }
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        int L = i, R = i;
        if (A[n] - A[i - 1] < a) break; 
        L = lower_bound(all(A), A[i] + a - (s[i] == 'a')) - A.begin();
        R = lower_bound(all(B), B[i] + b - (s[i] == 'b')) - B.begin() - 1;
        // cout << i << ' ' << L << ' ' << R << '\n';
        ans += max(R - L + 1, 0);
    } 
    cout << ans << '\n';
} 

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}