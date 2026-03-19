#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))

#define x first 
#define y second 

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

void solve () {
    int n;
    cin >> n;
    vector<LL> a(n + 1), use(n + 2, 0);
    int cnt = 0;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) {
        if (use[a[i] + 1]) {
            cnt ++;
        } 
        use[a[i]] = 1;
    }
    cout << n - cnt << '\n';
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}