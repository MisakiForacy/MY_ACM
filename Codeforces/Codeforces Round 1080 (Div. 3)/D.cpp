#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e18;

// 4 2 3 1 5

/*
1 - 1 -> 0
2 - 1 -> 1
3 - 1 -> 2
4 - 1 -> 3
5 - 1 -> 4
         10
*/

/*
1 - 2 -> 1
2 - 2 -> 0
3 - 2 -> 1
4 - 2 -> 2
5 - 2 -> 3
         7
*/

/*
1 - 3 -> 2
2 - 3 -> 1
3 - 3 -> 0
4 - 3 -> 1
5 - 3 -> 2
         6
*/

/*
1 - 4 -> 3
2 - 4 -> 2
3 - 4 -> 1
4 - 4 -> 0
5 - 4 -> 1
*/

/*
1 - 5 -> 4
2 - 5 -> 3
3 - 5 -> 2
4 - 5 -> 1
5 - 5 -> 0
*/

void solve() {
    int n;
    cin >> n;
    vector<LL> f(n + 1), a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> f[i];
    LL S = (f[1] + f[n]) / (n - 1), SS;
    SS = S;
    for (int i = 1;i <= n - 1;i ++) {
        a[i] = (S - f[i] + f[i + 1]) / 2;
        S -= 2 * a[i];
        SS -= a[i];
    }
    a[n] = SS;
    for (int i = 1;i <= n;i ++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}