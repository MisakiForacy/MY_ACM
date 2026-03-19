#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<LL> a(2 * n + 1, 0), b(2 * n + 1, 0);
    for (int i = 1;i <= 2 * n;i ++) {
        cin >> a[i];
        b[a[i]] ++;
    }
    sort(b.begin() + 1, b.end(), greater());
    LL ans = 0, cnt = 0, Ct = 0;
    for (int i = 1;i <= 2 * n;i ++) {
        if (!b[i]) break;
        if (b[i] & 1) {
            ans += 1;
            Ct += b[i];
        } else if ((b[i] / 2) & 1) {
            ans += 2;
        } else {
            ans += 2;
            cnt ++;
        }
    }
    if ((cnt & 1) && (Ct < 2)) ans -= 2;
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}