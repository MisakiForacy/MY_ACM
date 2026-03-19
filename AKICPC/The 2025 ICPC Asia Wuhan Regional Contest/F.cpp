#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

mt19937_64 rnd(time(0));

void solve () {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> p;
    for (int i = 1;i <= q;i ++) {
        int l, r;
        cin >> l >> r;
        p.push_back({l, r});
    }
    sort(all(p), [&](pair<int, int> x, pair<int, int> y) {
        if (x.x != y.x) return x.x < y.x;
        return x.y < y.y;
    });
    int L = 1, R = n, cnt = 1;
    for (int i = 0;i < q;i ++) {
        if (max(L, p[i].x) <= min(R, p[i].y)) {
            L = max(L, p[i].x);
            R = min(R, p[i].y);
        } else {
            L = p[i].x, R = p[i].y;
            cnt ++;
        }
    }
    cout << int(log2(cnt)) + 1 << '\n';
}

/*
3
5 5
1 5
1 1
2 2
4 4
5 5
5 2
1 3
3 5
3 3
1 1
2 2
3 3
*/

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}