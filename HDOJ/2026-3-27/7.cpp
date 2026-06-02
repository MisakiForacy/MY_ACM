#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = 2e6 + 10;

long long n, idx, odd, even;
int a[N], pre[N];
int p[M][2], use[N];

void solve() {
    cin >> n;
    use[idx ++] = 0;
    p[0][0] ++;
    odd = even = 0;
    for (int i = 1;i <= n;i ++) odd += (n - i + 2) / 2;
    even = (1 + n) * n / 2 - odd;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
        use[idx ++] = pre[i];
        odd += p[pre[i]][i & 1];
        even -= p[pre[i]][i & 1];
        p[pre[i]][i & 1] ++;
    }
    cout << even << ' ' << odd << '\n';
    for (int i = 0;i < idx;i ++) p[use[i]][0] = p[use[i]][1] = 0;
    idx = 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}