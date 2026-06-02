#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    stack<char> stk;
    int n;
    cin >> n;
    string s;
    cin >> s;   
    for (auto c : s) {
        if (stk.empty() || c == stk.top() || stk.top() == 'D') {
            stk.push(c);
        } else {
            stk.pop();
            stk.push('D');
        }
    }
    cout << siz(stk) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}