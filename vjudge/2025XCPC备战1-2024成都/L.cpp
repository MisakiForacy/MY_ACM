#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    LL a, b, c;
    cin >> a >> b >> c;
    cout << 100 << '\n';
    for (int i = 1;i <= 100;i ++) {
        if (i <= 50) {
            cout << a << ' ';
        } else if (i <= 95) {
            cout << b << ' ';
        } else if (i <= 99) {
            cout << c << ' ';
        } else {
            cout << c + 1 << '\n';
        }
    }
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}