#include <bits/stdc++.h>

using namespace std;
using LL = long long;

set<vector<int>> cnt;

// void dfs(int p, vector<int> v) {
//     if (p == 3) {
//         cnt.insert(v);
//         return;
//     }
//     for (int i = 1;i <= 4;i ++) {
//         v.push_back(i);
//         dfs(p + 1, v);
//         v.pop_back();
//     }
// }

mt19937_64 rnd(time(0));

void solve() {
    int n;
    cin >> n;
    set<int> idx;
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) idx.insert(i);
    auto get = [&]() -> array<int, 3> {
        int x = rnd() % n + 1;
        while (a[x]) x = rnd() % n + 1;
        int y = rnd() % n + 1;
        while (a[y] || y == x) y = rnd() % n + 1;
        int z = rnd() % n + 1;
        while (a[z] || z == x || z == y) z = rnd() % n + 1;
        if (x > y) swap(x, y);
        if (y > z) swap(y, z);
        if (x > y) swap(x, y);
        return {x, y, z};
    };
    auto ask = [&](int x, int y, int z) -> int {
        cout << "? " << x << ' ' << y << ' ' << z << '\n';
        int ret;
        cin >> ret;
        return ret;
    };
    int i, j, k, type = -1, res, cnt = 5500;
    while (cnt >= 4999) {
        array<int, 3> tp = get();
        i = tp[0], j = tp[1], k = tp[2];
        res = ask(i, j, k);
        if (res == 135) break;
        if (res == 15) break;
        if (res == 48) break;
        if (res == 35) break;
        if (res == 128) break;
        if (res == 243) break;
        if (res == 320) break;
        if (res == 240) break;
        if (res == 485) break;
        if (res == 768) break;
        if (res == 63) break;
        if (res == 3) a[i] = a[j] = a[k] = 3;
        cnt --;
    } 
    // if (res == )
}

int main() {
    // dfs(0, {});
    // cout << cnt.size() << '\n';
    // int u = 0;
    // for (auto v : cnt) {
    //     cout << v[0] << ' ' << v[1] << ' ' << v[2] << " : "; 
    //     double p = (v[0] + v[1] + v[2]) / 2.0;
    //     if (p * (p - v[0]) * (p - v[1]) * (p - v[2]) * 16 > 0) {
    //         cout << p * (p - v[0]) * (p - v[1]) * (p - v[2]) * 16;
    //         u ++;
    //     }
    //     cout << '\n';
    // }
    // cout << u << '\n';
    int T = 1;
    cin >> T;
    while (T --) solve();  
}