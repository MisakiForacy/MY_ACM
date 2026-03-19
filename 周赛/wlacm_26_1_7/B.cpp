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
    LL a, b, q;
    cin >> a >> b >> q;
    LL g = __gcd(a, b);
    LL m = a / g * b;
    vector<LL> p(m + 1, 0);
    for (int i = 1; i <= m;i ++) {
        LL bad = ((i % a) % b != (i % b) % a);
        p[i] = p[i - 1] + bad;
    }
    auto cal = [&](LL n) -> LL {
        if (n < 0) return 0;
        return (n / m) * p[m] + p[n % m];
    };
    while (q --) {
        LL l, r;
        cin >> l >> r;
        LL Ans = cal(r) - cal(l - 1);
        cout << Ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
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