#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

const LL inf = 1e15;

const int N = 1e6 + 10;

void solve() {
    LL n, k;
    cin >> n >> k;
    if (k <= n) {
        cout << -1 << '\n';
    } else {
        vector<int> use(k, 0), ans;
        use[0] = 1;
        int pre = 0, lst = 0;
        for (int i = 1;i <= n;i ++) {
            int x = lst + 1;
            while (1) {
                int nxt = (pre + x) % k;
                if (!use[nxt]) {
                    ans.push_back(x);
                    use[nxt] = 1;
                    pre = nxt;
                    lst = x;
                    break;
                }
                x ++;
            }
        }
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
