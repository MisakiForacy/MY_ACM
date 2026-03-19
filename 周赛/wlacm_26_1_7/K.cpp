#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

void solve() {
    int n, x, y, cnt = 0;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (a[i] <= x) {
            cnt ++;
        }
    }
    if (y >= x) {
        cout << (cnt + 1) / 2 << '\n';
    } else {
        cout << n << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}

/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
*/

/*
1 2 3 4
5 6 7 8
9

9 2 3 4
5 6 7 8
1

9 1 2 3
4 5 6 7
8
*/