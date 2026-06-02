#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    string s, t;
    cin >> s >> t;
    stack<char> p1, p2;
    for (auto c : s) {
        if (siz(p1) < 3) {
            p1.push(c);
        } else {
            if (c != ')') {
                p1.push(c);
            } else {
                string tp;
                for (int i = 0;i < 3;i ++) {
                    tp = p1.top() + tp;
                    p1.pop();
                }
                if (tp != "(xx") {
                    for (char cc : tp) p1.push(cc);
                    p1.push(c);
                } else {
                    p1.push('x');
                    p1.push('x');
                }
            }
        }
    }
    for (auto c : t) {
        if (siz(p2) < 3) {
            p2.push(c);
        } else {
            if (c != ')') {
                p2.push(c);
            } else {
                string tp;
                for (int i = 0;i < 3;i ++) {
                    tp = p2.top() + tp;
                    p2.pop();
                }
                if (tp != "(xx") {
                    for (char cc : tp) p2.push(cc);
                    p2.push(c);
                } else {
                    p2.push('x');
                    p2.push('x');
                }
            }
        }
    }
    cout << (p1 == p2 ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}