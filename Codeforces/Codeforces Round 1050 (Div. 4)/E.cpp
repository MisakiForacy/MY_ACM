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
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    map<int, int> mp, p;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) mp[a[i]] ++;
    for (auto [num, v] : mp) {
        if (v % k) {
            cout << 0 << '\n';
            return;
        }
        p[num] = v / k;
    }
    int L = 1;
    map<int, int> use;
    LL ans = 0;
    for (int i = 1;i <= n;i ++) {
        use[a[i]] ++;
        while (use[a[i]] > p[a[i]]) {
            use[a[L]] --;
            L ++;
        }
        ans += i - L + 1;
    }
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