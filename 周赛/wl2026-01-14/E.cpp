#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    string s;
    cin >> s;
    int n = siz(s);
    s = ' ' + s + ' ';
    cout << s[1];
    for (int i = 2;i <= n;i ++) {
        if (s[i] == s[i - 1]) {
            while (s[i] == s[i - 1] || s[i] == s[i + 1]) {
                s[i] = (s[i] - 'a' + 1) % 26 + 'a'; 
            }
        }
        cout << s[i];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}