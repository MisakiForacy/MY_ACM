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
    int n;
    cin >> n;
    LL ans = 0;
    vector<LL> a(n + 1), o, e;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        if (a[i] & 1) o.push_back(a[i]);
        else ans += a[i];
    }
    if (siz(o) == 0) {
        cout << 0 << '\n';
        return;
    } else {
        sort(all(o), [&](LL x, LL y) {
            return x > y;
        });
        for (int i = 0;i < (siz(o) + 1) / 2;i ++) {
            ans += o[i];
        }
        cout << ans << '\n';
    }
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