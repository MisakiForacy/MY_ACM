#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    LL n;
    cin >> n;
    map<pair<int, int>, int> mp;
    for (int d = 1;d <= n / 2 + 1;d ++) {
        for (int i = 1;i <= n;i ++) {
            int u = i;
            int v = (i + d - 1) % n + 1;
            if (u == v) continue;
            if (u > v) swap(u, v);
            if (mp.count({u, v})) continue;
            mp[{u, v}] = 1;
            cout << u << ' ' << v << '\n';
            int x;
            cin >> x;
            if (x) return;
        }
    }
}

void brute() {

}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}