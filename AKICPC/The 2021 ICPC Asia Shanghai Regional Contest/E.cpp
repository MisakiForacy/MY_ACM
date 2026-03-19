#include<bits/stdc++.h>
#define For(i, n, m) for(ll i = n; i <= m; ++i)
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, k, a[100010], f[100010], pre[100010];



int main () {
    cin.tie (0), ios::sync_with_stdio(false);
    cin >> n >> k;
    For (i, 1, n) cin >> a[i];
    if (!k) {
        cout << n << endl;
        return 0;
    }
    sort (a + 1, a + n + 1);
    // For (i, 1, n) cout << a[i] << " \n"[i == n];
    f[1] = 1, pre[1] = 1;
    For (i, 2, n) {
        ll Lower = a[i] - k;
        if (Lower <= 0) {
            f[i] = 1, pre[i] = pre[i - 1];
            continue;
        }
        auto T = upper_bound (a + 1, a + i + 1, Lower);
        if (T - a - 1 != i) {
            // cout << "Found " << (ll)(T - a - 1) << ' ' << i << endl;
            f[i] = pre[T - a - 1] + 1, pre[i] = max (pre[i - 1], f[i]);
        }
        else {
            // cout << "Skipped " << i << endl;
            f[i] = 1, pre[i] = pre[i - 1];
        }
    }
    cout << pre[n] << endl;
}