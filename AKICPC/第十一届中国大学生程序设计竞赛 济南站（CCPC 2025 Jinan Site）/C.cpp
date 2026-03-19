#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

void solve () {
    int m;
    cin >> m;
    vector <int> p (m + 1, 0), pos (1000010, 0);
    for (int i = 1;i <= m;i ++) cin >> p[i], pos[p[i]] = i;
    int n; cin >> n;
    for (int i = 1;i <= n;i ++) {
        int l; cin >> l;
        vector <int> dp (m + 1, 0);
        dp[0] = l + 1;
        for (int j = 1;j <= l;j ++) {
            int x; cin >> x;
            if (pos[x] && dp[pos[x] - 1] > dp[pos[x]]) {
                dp[pos[x]] ++;
            }
        }
        cout << dp[m] << '\n';
    }
}

/*
4
4 2 1 3
3
8 4 2 1 3 4 2 3 1
9 1 4 2 4 1 2 1 3 3
12 1 1 2 3 4 2 1 1 2 1 3 3
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}