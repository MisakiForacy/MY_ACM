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
    vector<LL> a(n + 1, 0);
    set<LL> ans;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    map<pair<int, int>, int> mp;
    for (int i = 2;i <= n;i ++) {
        LL x, y, z, u, v;
        u = a[i];
        v = a[i - 1];
        x = a[i] & a[i - 1];
        y = a[i] | a[i - 1];
        z = a[i] ^ a[i - 1];
        ans.insert(a[i]), ans.insert(a[i - 1]);
        ans.insert(x), ans.insert(y), ans.insert(z);
        mp[{u, v}] = mp[{v, u}] = 1;
        priority_queue<pair<int, int>> p;
        if (!mp.count({u, x}) && u && x) p.push({u, x});
        if (!mp.count({u, y}) && u && y) p.push({u, y});
        if (!mp.count({u, z}) && u && z) p.push({u, z});
        if (!mp.count({x, v}) && x && v) p.push({x, v});
        if (!mp.count({y, v}) && y && v) p.push({y, v});
        if (!mp.count({z, v}) && z && v) p.push({z, v});
        while (siz(p)) {
            auto [uu, vv] = p.top();
            p.pop();
            if (mp.count({uu, vv})) {
                continue;
            } else {
                LL xx, yy, zz;
                mp[{uu, vv}] = mp[{vv, uu}] = 1;
                xx = uu & vv;
                yy = uu | vv;
                zz = uu ^ vv;
                ans.insert(uu), ans.insert(vv);
                ans.insert(xx), ans.insert(yy), ans.insert(zz);
                if (!mp.count({uu, xx}) && uu && xx) p.push({uu, xx});
                if (!mp.count({uu, yy}) && uu && yy) p.push({uu, yy});
                if (!mp.count({uu, zz}) && uu && zz) p.push({uu, zz});
                if (!mp.count({xx, vv}) && xx && vv) p.push({xx, vv});
                if (!mp.count({yy, vv}) && yy && vv) p.push({yy, vv});
                if (!mp.count({zz, vv}) && zz && vv) p.push({zz, vv});
            }
            mp[{uu, vv}] = mp[{vv, uu}] = 1;
        }
    }
    cout << siz(ans) << '\n';
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("oout.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}