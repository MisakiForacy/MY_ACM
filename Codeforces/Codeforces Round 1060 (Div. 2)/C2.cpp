#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cerr << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int N = 2e5 + 10;
const LL inf = 1e15;
const int P = 131;

mt19937_64 rng(time(0));

vector<int> p, s(N, 0);
// set<int> sp;

void Euler() {
    s[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!s[i]) p.push_back(i);
        for (int j = 0;j < siz(p) && i * p[j] < N;j ++) {
            s[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

struct node 
{
    LL a, b;
    bool operator < (const node&that) const {
        return b < that.b;
    }
};

void fxy_ac() {
    int n;
    cin >> n;
    vector<node> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].a;
    for (int i = 0;i < n;i ++) cin >> p[i].b;
    sort(all(p));
    map<int, int> mp;
    set<int> sp;
    for (int i = 0;i < n;i ++) {
        for (int j = 1;j * j <= p[i].a;j ++) {
            if (p[i].a % j) continue;
            int x = j, y = p[i].a / j;
            if (s[x] == 0) mp[x] ++, sp.insert(x);
            if (x != y && s[y] == 0) mp[y] ++, sp.insert(y);
        }
    }
    for (auto [k, v] : mp) {
        if (v > 1) {
            cout << 0 << '\n';
            return;
        }
    }
    vector<LL> bb;
    for (int i = 0;i < n;i ++) {
        if (p[i].a & 1) {
            bb.push_back(p[i].b);
        }
    }
    sort(all(bb));
    LL ans = inf;
    if (siz(bb) > 1) ans = bb[0] + bb[1];
    else ans = bb[0];
    // cout << ans << '\n';
    for (int i = 0;i < n;i ++) {
        int v = p[i].a + 1;
        for (int j = 1;j * j <= v;j ++) {
            if (v % j) continue;
            int x = j, y = v / j;
            if (mp.count(x)|| mp.count(y)) {
                ans = min(ans, p[i].b);
            }
        }
    }
    for (int i = 0;i < n;i ++) {
        // cout << p[i].a << ' ' << p[i].b << '\n';
        if (p[i].b * 2 >= ans) break;
        for (int x : sp) {
            if (p[i].a % x == 0) continue;
            ans = min(ans, (x - p[i].a % x) * p[i].b);
        }
    }
    cout << ans << '\n';
}

void brute() {

}

int main() {
    Euler();
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}