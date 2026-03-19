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
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    LL bit = 0;
    for (int i = 1;i <= n;i ++) bit |= a[i];
    vector<LL> p;
    for (int i = 1;i <= n;i ++) {
        LL tmp = a[i];
        for (int x : p) {
            tmp = min(tmp, tmp ^ x);
        }
        if (tmp != 0) {
            p.push_back(tmp);
        }
    }
    LL ans = 1LL << siz(p);
    cout << ans << '\n';
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