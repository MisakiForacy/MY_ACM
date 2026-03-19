#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL N = 1e6 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1), b(m + 1), cnt(n + m + 1, 0), c(n + m + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], cnt[a[i]] ++;
    for (int i = 1;i <= m;i ++) cin >> b[i];
    for (int i = 1;i <= n + m;i ++) {
        for (int j = i;j <= n + m;j += i) {
            c[j] += cnt[i];
        }
    }
    int A = 0, B = 0, AB = 0;
    for (int i = 1;i <= m;i ++) {
        if (c[b[i]] == 0) B ++;
        else if (c[b[i]] == n) A ++;
        else AB ++;
    }
    if (AB & 1) {
        if (B > A) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    } else {
        if (B >= A) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}