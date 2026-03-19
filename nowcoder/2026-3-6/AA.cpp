#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = ' ' + s + ' ';
    t = ' ' + t + ' ';
    int ok1 = 1, ok2 = 1;
    for (int i = 1;i <= n;i ++) {
        if (t[i] == t[i - 1]) ok1 = 0;
    }
    for (int i = 1;i <= n;i ++) {
        if (s[i] != '0') ok2 = 0;
    }
    if (ok1 || ok2) {
        cout << (t == s ? "YES\n" : "NO\n");
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}