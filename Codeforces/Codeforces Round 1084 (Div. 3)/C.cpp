#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    stack<char> stk;
    for (int i = 1;i <= n;i ++) {
        char c;
        cin >> c;
        if (siz(stk) && stk.top() == c) {
            stk.pop();
        } else {
            stk.push(c);
        }   
    }
    cout << (siz(stk) ? "NO\n" : "YES\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}