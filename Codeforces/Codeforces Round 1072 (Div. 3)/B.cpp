#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    LL s, k, m;
    cin >> s >> k >> m;
    if (k >= s) {
        LL t = m % k;
        cout << max(0LL, s - t) << '\n';
    } else {
        LL t = m % k;
        LL f = m / k & 1;
        LL Ans;
        if (f) {
            Ans = max(0LL, k - t);
        } else {
            Ans = max(0LL, s - t);
        }
        cout << Ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}