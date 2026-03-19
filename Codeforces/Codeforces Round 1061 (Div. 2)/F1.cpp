#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), use(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        int Min = a[i] - 2;
        int Max = a[i] - 1;
        while (a[i] > 2 && !use[Min] && !use[Max]) {
            int x = 0, y = 0;
            for (int j = i + 1;j <= n;j ++) {
                if (a[j] == Min) x = j;
                if (a[j] == Max) y = j;
                if (x && y) break;
            }
            a[i] -= 2, a[x] += 1, a[y] += 1;
            Min = a[i] - 2;
            Max = a[i] - 1;
        }
        use[a[i]] = 1;
    }
    for (int i = 1;i <= n;i ++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}