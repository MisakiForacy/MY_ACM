#include <bits/stdc++.h>

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

void solve() {
    LL n, w, h, l, W, H, L;
    LL res = 0;
    w = h = l = 0;
    cin >> W >> H >> L;
    cin >> n;
    map<array<LL, 3>, LL> hash;
    hash[{w, h, l}] = rnd();
    hash[{W, h, l}] = rnd();
    hash[{W, H, l}] = rnd();
    hash[{w, H, l}] = rnd();
    hash[{w, h, L}] = rnd();
    hash[{W, h, L}] = rnd();
    hash[{W, H, L}] = rnd();
    hash[{w, H, L}] = rnd();
    res ^= hash[{w, h, l}];
    res ^= hash[{W, h, l}];
    res ^= hash[{W, H, l}];
    res ^= hash[{w, H, l}];
    res ^= hash[{w, h, L}];
    res ^= hash[{W, h, L}];
    res ^= hash[{W, H, L}];
    res ^= hash[{w, H, L}];
    LL tot = W * H * L, sum = 0;
    for (int i = 1;i <= n;i ++) {
        cin >> w >> h >> l >> W >> H >> L;
        sum += (W - w) * (H - h) * (L - l);
        if (!hash.count({w, h, l})) hash[{w, h, l}] = rnd();
        if (!hash.count({W, h, l})) hash[{W, h, l}] = rnd();
        if (!hash.count({W, H, l})) hash[{W, H, l}] = rnd();
        if (!hash.count({w, H, l})) hash[{w, H, l}] = rnd();
        if (!hash.count({w, h, L})) hash[{w, h, L}] = rnd();
        if (!hash.count({W, h, L})) hash[{W, h, L}] = rnd();
        if (!hash.count({W, H, L})) hash[{W, H, L}] = rnd();
        if (!hash.count({w, H, L})) hash[{w, H, L}] = rnd();
        res ^= hash[{w, h, l}];
        res ^= hash[{W, h, l}];
        res ^= hash[{W, H, l}];
        res ^= hash[{w, H, l}];
        res ^= hash[{w, h, L}];
        res ^= hash[{W, h, L}];
        res ^= hash[{W, H, L}];
        res ^= hash[{w, H, L}];
    }
    cout << ((!res && sum == tot) ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}