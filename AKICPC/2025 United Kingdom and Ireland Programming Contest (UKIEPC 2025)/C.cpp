#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

map<char, int> h;

void init() {
    // A 、 D 、 O 、 P 、 Q 、 R
    for (char c = 'A';c <= 'Z';c ++) h[c] = 0;
    h['A'] = h['D'] = h['O'] = h['P'] = h['Q'] = h['R'] = 1;
    h['B'] = 2;
}

void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> use, idx;
    for (char c : s) use.push_back(h[c]);
    vector<vector<char>> a(11, vector<char> (101, '.'));
    int p = 1;
    for (int i = 1;i <= siz(s);i ++) {
        idx.push_back(p);
        for (int j = 0;j < siz(t);j ++) {
            for (int k = 1;k <= 10;k ++) {
                a[k][p] = t[j];
            }
            p ++;
        }
        p ++;
    }
    for (int i = 0;i < siz(use);i ++) {
        if (use[i] == 0) continue;
        if (use[i] == 1) a[2][idx[i] + 1] = '.';
        if (use[i] == 2) a[2][idx[i] + 1] = '.', a[5][idx[i] + 1] = '.';
    }
    for (int i = 1;i <= 10;i ++) {
        for (int j = 1;j <= 100;j ++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}