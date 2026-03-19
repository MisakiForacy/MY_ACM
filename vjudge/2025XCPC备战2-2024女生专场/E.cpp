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
    // vector<pair<int, vector<int>>> p;
    map<int, vector<int>> mp;
    for (int i = 1;i <= n;i ++) {
        int c;
        cin >> c;
        vector<int> tmp(c + 1);
        for (int j = 1;j <= c;j ++) {
            cin >> tmp[j];
        }
        mp[i] = tmp;
        // p.push_back({i, tmp});
    }
    // for (auto [k, v] : mp) {
    //     cout << k << " : \n";
    //     for (int x : v) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }
    vector<pair<int, int>> ans;
    // sort(all(p), [&](pair<int, vector<int>> x, pair<int, vector<int>> y) {
    //     return siz(x.y) < siz(y.y);
    // });
    vector<int> f(n + 1, 0);
    for (int i = 1;i <= n;i ++) f[i] = i;
    auto findx = [&](auto findx, int x) -> int {
        if (x != f[x]) {
            f[x] = findx(findx, f[x]);
        }
        return f[x];
    };
    auto merge = [&](int u, int v) -> void {
        u = findx(findx, u);
        v = findx(findx, v);
        if (u == v) return;
        if (u < v) swap(u, v);
        f[u] = v;
    };
    for (int i = n - 1;i >= 0;i --) {
        int u = i + 1;
        for (int v : mp[u]) {
            if (v == 0) continue;
            v = findx(findx, v);
            ans.push_back({u, v});
            merge(u, v);
        }
    }
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
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