#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<int, int>;

const double PI = 3.14159265358979323846;

void solve() {
    int n, c, x;
    cin >> n >> c;
    vector<int> p(n + 1, -1);
    while (cin >> x) {
        if (x == -1) break;
        p[x] = 1;
    }
    while (cin >> x) {
        if (x == -1) break;
        p[x] = 0;
    }
    vector<int> Tp(n + 1, 1);
    auto run = [&](char c) -> void {
        if (c == '1') {
            for (int i = 1;i <= n;i ++) Tp[i] ^= 1;
        } else if (c == '2') {
            for (int i = 1;i <= n;i += 2) Tp[i] ^= 1; 
        } else if (c == '3') {
            for (int i = 2;i <= n;i += 2) Tp[i] ^= 1;
        } else if (c == '4') {
            for (int i = 1;i <= n;i += 3) Tp[i] ^= 1;
        }
    };
    auto init = [&]() -> void {
        for (int i = 1;i <= n;i ++) Tp[i] = 1;
    };
    auto check = [&]() -> int {
        int ok = 1;
        for (int i = 1;i <= n;i ++) {
            if (~p[i] && p[i] != Tp[i]) {
                ok = 0;
            }
        }
        return ok;
    };
    set<vector<int>> Ans;
    if (c == 0) {
        if (check()) Ans.insert(Tp);
    } else if (c == 1) {
        vector<string> res = {"1", "2", "3", "4"};
        for (auto s : res) {
            init();
            for (char c : s) {
                run(c);
            }
            if (check()) Ans.insert(Tp);
        }
    } else if (c == 2) {
        vector<string> res = {"1", "2", "3", "14", "24", "34"};
        if (check()) Ans.insert(Tp);
        for (auto s : res) {
            init();
            for (char c : s) {
                run(c);
            }
            if (check()) Ans.insert(Tp);
        }
    } else {
        vector<string> res = {"1", "2", "3", "4", "14", "24", "34"};
        if (check()) Ans.insert(Tp);
        for (auto s : res) {
            init();
            for (char c : s) {
                run(c);
            }
            if (check()) Ans.insert(Tp);
        }
    }
    if (siz(Ans)) {
        for (auto v : Ans) {
            for (int i = 1;i <= n;i ++)
                cout << v[i];
            cout << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
} 
// 5 4 4 3 3 2 2 1 1
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}