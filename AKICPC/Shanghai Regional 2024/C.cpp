#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first 
#define y second 
using namespace std;
using LL = long long;

/*
3
2 4
4 4
6 7
*/

void solve() {
    LL l, r;
    cin >> l >> r;
    if (l & 1) {
        if (((r - l + 1) & 1) || r >= l * 2) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    } else {
        if ((l + 1) * 2 > r) {
            if ((r - l + 1) & 1) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        } else {
            cout << "Bob\n";
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}