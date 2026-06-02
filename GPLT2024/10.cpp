#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    // cin >> n;
    scanf("%d", &n);
    getchar();
    map<string, vector<string>> dict;
    for (int i = 1;i <= n;i ++) {
        string s, t;
        getline(cin, s);
        if (s[0] != ' ') {
            t.push_back(s[0]);
        }
        for (int i = 0;i < siz(s);i ++) {
            if (s[i] == ' ' && s[i + 1] != ' ') {
                t.push_back(s[i + 1]);
            }
        }
        // cout << t << '\n';
        dict[t].push_back(s);
    }
    for (auto &[k, v] : dict) sort(all(v));
    int m;
    scanf("%d", &m);
    getchar();
    for (int i = 1;i <= m;i ++) {
        string s, t;
        getline(cin, s);
        if (s[0] != ' ') {
            t.push_back(s[0]);
        }
        for (int i = 0;i < siz(s);i ++) {
            if (s[i] == ' ' && s[i + 1] != ' ') {
                t.push_back(s[i + 1]);
            }
        }
        if (siz(dict[t]) == 0) {
            cout << s << '\n';
        } else {
            for (int i = 0;i < siz(dict[t]);i ++) {
                cout << dict[t][i] << "|\n"[i == siz(dict[t]) - 1];
            }
        }
    }
}

int main() {
    // cout << fixed << setprecision(2);
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}