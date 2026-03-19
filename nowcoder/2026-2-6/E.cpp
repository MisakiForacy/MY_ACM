#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;


    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    /*
    000
    001
    011
    */
    /*
    010101   000001 2   
    011101   010101 4   
    000101   000101 3   
    000000   011101 5 
    000001   000000 1
    111101   111101 6   
    */
    /*
    0010101
    0000001
    0110101
    0000101
    0111101
    0000000
    1111101
    */
    /*
    00000101
    00010101
    00110101
    01110101
    00000001
    11110101
    00000000
    11111101
    */

    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    auto S = [&](int st, int ed) -> void {
        for (int i = st;i < ed;i ++) {
            swap(a[i], a[i + 1]);
        }
        for (int i = 1;i <= n;i ++) {
            for (int j = st;j < ed;j ++) {
                swap(a[i][j], a[i][j + 1]);
            }
        }
    };
    for (int i = 1;i <= n;i ++) {
        for (int j = n;j > n - i + 1;j --) {
            a[i][j] = 1;
        }
    }
    int Up = 1, Down = n - 1;
    int use = (n - 2) / 3;
    // cout << use << '\n';
    while (use --) {
        S(Up, Down);
        Down -= 2;
    }
    if ((n + 1) % 3 == 1 && n > 1) {
        swap(a[1], a[2]);
    } else if ((n + 1) % 3 == 2) {
        S(1, 2);
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}