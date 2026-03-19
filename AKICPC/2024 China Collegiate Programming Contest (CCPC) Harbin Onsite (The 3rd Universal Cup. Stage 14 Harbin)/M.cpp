#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first
#define y second
using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5;

int f(int a, int b) {
    int i = b;
    while (i >= 2) {
        if (a % i == 0) {
            return a / i;
        }
        i --;
    }
    return a;
}

/*
3
5
451
114514
*/

void solve() {
    int n;
    cin >> n;
    LL ans = 0;
    // for (int i = 1;i <= n;i ++) {
    //     LL val = f(n, i);
    //     ans += val;
    //     cout << val << ' ';
    // }
    // cout << '\n';
    // cout << ans << '\n';
    set<LL> p;
    for (int i = 1;i <= sqrt(n);i ++) {
        if (n % i == 0) {
            p.insert(n / i);
            p.insert(i);
        }
    }
    vector<LL> a;
    for (LL x : p) a.push_back(x);
    ans = 0;
    for (int i = 1;i < siz(a);i ++) {
        ans += (a[i] - a[i - 1]) * (n / a[i - 1]);   
    }
    ans += 1;
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
}