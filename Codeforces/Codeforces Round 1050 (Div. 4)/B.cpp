#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x
#define N 1e5 + 10;
using namespace std;
using LL = long long;

mt19937_64 rng(time(0));

void fxy_ac() {
    LL a, b, n, m, x, y;
    cin >> a >> b >> n >> m;
    for (int i = 1;i <= a;i ++) cin >> x;
    for (int i = 1;i <= b;i ++) cin >> y;
    cout << a + b << '\n';
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}