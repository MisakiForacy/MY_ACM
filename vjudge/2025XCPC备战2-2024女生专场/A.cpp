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
    LL z0, h, u0, v0, u1, v1;
    cin >> z0 >> h >> u0 >> v0 >> u1 >> v1;
    LL z1 = z0 + h;
    LL q;
    cin >> q;
    while (q --) {
        LL x, y, z;
        cin >> x >> y >> z;
        if (!(z0 <= z && z <= z1)) {
            cout << "NO\n";
            continue;
        }
        if (x < min(u0, u1) || x > max(u0, u1) || y < min(v0, v1) || y > max(v0, v1)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}

/*
1 1 -1 -1 1 1
3
-1-1 1
0 0 2
1 2 2
*/

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}