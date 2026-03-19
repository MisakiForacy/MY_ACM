#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

void solve() {
    string s = "";
    int n;
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        string t;
        cin >> t;
        string s1 = s + t;
        string s2 = t + s;
        s = min(s1, s2);
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}