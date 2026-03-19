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
    vector<LL> a(n);
    map<LL, LL> mp;
    for (int i = 0;i < n;i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    LL val = 0, ans = 0;
    vector<LL> p;
    LL cnt = 0;
    for (auto [k, v] : mp) {
        if (!(v & 1)) {
            val += k * v;
            cnt += v / 2;
        } else {
            val += k * (v - 1);
            p.push_back(k);
        }
    }
    sort(all(p));
    if (cnt > 1) ans = max(ans, val);
    for (int i = 0;i < siz(p);i ++) {
        int nxt = lower_bound(all(p), p[i] + val) - p.begin() - 1;
        if (nxt <= i) {
            if (p[i] < val) {
                ans = max(ans, val + p[i]);
            }
        } else {
            ans = max(ans, val + p[i] + p[nxt]);
        }
    }
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
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}