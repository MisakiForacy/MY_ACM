#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 3;j <= n;j ++) {
            if (pos[j] < pos[j - 1] && pos[j] < pos[j - 2]) {
                swap(a[pos[j]], a[pos[j - 2]]);
                swap(pos[j], pos[j - 2]);
                swap(a[pos[j]], a[pos[j - 1]]);
                swap(pos[j], pos[j - 1]);
            }
        }
    }
    for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
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