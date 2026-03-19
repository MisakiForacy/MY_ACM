#include <bits/stdc++.h>
#define x first
#define y second
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x
#define N 1e5 + 10;
using namespace std;
using LL = long long;

mt19937_64 rng(time(0));

void fxy_ac() {
    LL n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n + 1);
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        cin >> p[i].x >> p[i].y;
        if (p[i].y == p[i - 1].y) {
            ans += (p[i].x - p[i - 1].x) / 2 * 2; 
        } else {
            ans += p[i].x - p[i - 1].x - (p[i].x - p[i - 1].x + 1 & 1);
        }
    }
    ans += m - p[n].x;
    cout << ans << '\n';
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}