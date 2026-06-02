#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> stk;
    for (char c : s) {
        if (stk.empty()) {
            stk.push(c);
        } else if (c == '(') {
            stk.push(c);
        } else {
            if (stk.top() == '(') {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
    }
    cout << siz(stk) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}