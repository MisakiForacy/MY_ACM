#include<bits/stdc++.h>
#define For(i, n, m) for(ll i = n; i <= m; ++i)
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, k;
ll f[101][101][3010]; // [n][k][SUMt]
struct Tp { ll v, t; } a[101];

inline bool cmp (Tp a, Tp b) {
    return a.v > b.v;
}

int main () {
    cin.tie (0), ios::sync_with_stdio (false);
    cin >> n >> k; For (i, 1, n) cin >> a[i].v >> a[i].t;
    sort (a + 1, a + n + 1, cmp);
    For (j, 0, k) For (T, 0, 3000) f[0][j][T] = -1;
    f[0][0][1500] = 0;
    For (i, 1, n) {
        For (j, 0, k) {
            For (T, 0, 3000) {
                f[i][j][T] = f[i - 1][j][T];
            }
        }
        For (j, 0, k) {
            For (T, 0, 3000) {
                if (T - a[i].t >= 0 && f[i - 1][j][T - a[i].t] != -1)
                    f[i][j][T] = max (f[i][j][T], f[i - 1][j][T - a[i].t] + a[i].v);
                if (T + a[i].t <= 3000 && f[i - 1][j][T + a[i].t] != -1)
                    f[i][j][T] = max (f[i][j][T], f[i - 1][j][T + a[i].t] + a[i].v);                    
            }
        }
        For (j, 1, k) {
            a[i].t *= 2;
            For (T, 0, 3000) {
                if (T - a[i].t >= 0 && f[i - 1][j - 1][T - a[i].t] != -1)
                    f[i][j][T] = max (f[i][j][T], f[i - 1][j - 1][T - a[i].t] + a[i].v);
                if (T + a[i].t <= 3000 && f[i - 1][j - 1][T + a[i].t] != -1)
                    f[i][j][T] = max (f[i][j][T], f[i - 1][j - 1][T + a[i].t] + a[i].v);                    
            }
            a[i].t /= 2;
        }
    }
    ll ans = 0;
    For (i, 0, k) ans = max (ans, f[n][i][1500]);
    cout << ans << endl;
}