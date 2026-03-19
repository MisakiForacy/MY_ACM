#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve () {
    string opt;
    cin >> opt;
    if (opt == "first") {
        int n;
        cin >> n;
        string s;
        for (int i = 1;i <= n;i ++) {
            LL x;
            cin >> x;
            for (int j = 1;j <= 10;j ++) {
                s.push_back(x % 10 + 'a');
                x /= 10;
            }
        }
        cout << s << '\n';
    } else {
        string s;
        cin >> s;
        cout << siz(s) / 10 << '\n';
        for (int i = 0;i < siz(s);i += 10) {
            LL ret = 0;
            for (int j = i + 9;j >= i;j --) {
                ret *= 10;
                ret += s[j] - 'a';
            }
            cout << ret << ' ';
        }
        cout << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}