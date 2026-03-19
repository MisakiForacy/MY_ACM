#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second
using namespace std;
using LL = long long;

mt19937_64 rng(time(0));

const int N = 2e5 + 10;
const LL inf = 1e15 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int> (n + 1, 0));
    if (k < n || n * n - k + 1 < n) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int num = k;
    vector<int> use(n * n + 2, 0);
    for (int i = 1;i <= n;i ++) a[i][i] = num, use[num ++] = 1;
    num = 1;
    for (int i = 2;i <= n;i ++) a[i][1] = num, use[num ++] = 1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            if (!a[i][j]) {
                while (use[num]) num ++;
                a[i][j] = num;
                use[num ++] = 1;
            }
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}