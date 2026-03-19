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
    unordered_map<LL, int> mp;
    auto get = [&](LL u, LL v) -> LL {
        return u * LL(1e9) + v;
    };
    auto use = [&](LL x) -> pair<LL, LL> {
        return {x / LL(1e9), x % LL(1e9)};
    };
    for (int i = 2;i <= n;i ++) {
        LL x, y, z, u, v;
        u = a[i];
        v = a[i - 1];
        x = u & v;
        y = u | v;
        z = u ^ v;
        ans.insert(a[i]), ans.insert(a[i - 1]);
        ans.insert(x), ans.insert(y), ans.insert(z);
        mp[get(u, v)] = mp[get(v, u)] = 1;
        priority_queue<LL> p;
        if (!mp.count(get(u, x))) p.push(get(u, x));
        if (!mp.count(get(u, y))) p.push(get(u, y));
        if (!mp.count(get(u, z))) p.push(get(u, z));
        if (!mp.count(get(x, v))) p.push(get(x, v));
        if (!mp.count(get(y, v))) p.push(get(y, v));
        if (!mp.count(get(z, v))) p.push(get(z, v));
        while (siz(p)) {
            auto [uu, vv] = use(p.top());
            p.pop();
            if (mp.count(get(uu, vv))) {
                continue;
            } else {
                LL xx, yy, zz;
                mp[get(uu, vv)] = mp[get(vv, uu)] = 1;
                xx = uu & vv;
                yy = uu | vv;
                zz = uu ^ vv;
                ans.insert(uu), ans.insert(vv);
                ans.insert(xx), ans.insert(yy), ans.insert(zz);
                if (!mp.count(get(uu, xx))) p.push(get(uu, xx));
                if (!mp.count(get(uu, yy))) p.push(get(uu, yy));
                if (!mp.count(get(uu, zz))) p.push(get(uu, zz));
                if (!mp.count(get(xx, vv))) p.push(get(xx, vv));
                if (!mp.count(get(yy, vv))) p.push(get(yy, vv));
                if (!mp.count(get(zz, vv))) p.push(get(zz, vv));
            }
            mp[get(uu, vv)] = mp[get(vv, uu)] = 1;
        }
    }
    cout << siz(ans) << '\n';
}

void brute() {
    cout << 1000 << '\n';
    for (int i = 1;i <= 1000;i ++) {
        cout << rng() % LL(1e9) << ' ';
    }
    cout << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("in.txt", "w", stdout);
    // freopen("oout.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        // fxy_ac();
        brute();
    }
}