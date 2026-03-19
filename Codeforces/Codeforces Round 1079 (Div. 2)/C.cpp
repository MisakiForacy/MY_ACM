#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    LL a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << "Alice\n";
    } else {
        LL d = b - a;
        if (b >= 3 * d) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}   

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}