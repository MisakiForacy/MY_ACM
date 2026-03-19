#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

const LL P = 998244353;

void solve() {
    LL K;
    cin >> K;
    LL Ans = 0;
    for (int i = 2;i <= K - 4;i ++) {
        for (int j = i + 2;j <= K - 2;j ++) {
            LL x = i, y = j - i, z = K - j;
            LL Mx = max({x, y, z});
            LL Sm = K - Mx;
            Ans += (x - 1) * (y - 1) % P * (z - 1) % P * Sm % P;
            Ans %= P;
        }
    }
    cout << Ans << '\n';
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