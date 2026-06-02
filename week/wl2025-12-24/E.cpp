#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int Mid = n / 2 + 1;
    int Cnt = 1, ok = 1;
    LL Ans = a[Mid];
    for (int i = Mid + 1;i <= n;i ++) {
        LL use = a[i] - a[i - 1];
        if (use * Cnt <= k) k -= use * Cnt, Ans = a[i];
        else {
            ok = 0;
            Ans += k / Cnt;
            break;
        }
        Cnt ++;
    }    
    if (ok) Ans += k / Cnt;
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}