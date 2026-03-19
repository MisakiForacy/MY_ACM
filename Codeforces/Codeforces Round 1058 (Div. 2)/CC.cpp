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
    auto f = [&](LL x) -> LL {
        if (x == 0) return 0;
        while (x % 2 == 0) x /= 2;
        int k = log2(x);
        LL y = 0;
        for (int j = 0;j <= k;j ++) {
            if (x >> j & 1) {
                y += 1LL << k - j;
            }
        }
        return y;
    };
    auto ff = [&](LL x) -> int {
        int v = 0;
        for (int i = log2(x);i >= 0;i --) {
            cout << (x >> i & 1) << ' ';
            v += (x >> i & 1);
        }
        cout << '\n';
        return v;
    };
    ff(n);
    // cout << f()
    int ok = 0;
    for (int i = 0;i < n * 100;i ++) {
        if ((i ^ f(i)) == n) {
            ok = 1;
            cout << i << '\n';
        }
    }
    cout << ok << '\n';
    int cnt = 0;
    for (int i = 0;i < 60;i ++) {
        if (n >> i & 1) cnt ++;
    }
    if (cnt & 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

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