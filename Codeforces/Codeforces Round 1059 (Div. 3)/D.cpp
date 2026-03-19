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
    int n;
    cin >> n;
    auto ask1 = [&](int l, int r) -> int {
        cout << "1 " << l << ' ' << r << '\n';
        int x;
        cin >> x;
        return x;
    };
    auto ask2 = [&](int l, int r) -> int {
        cout << "2 " << l << ' ' << r << '\n';
        int x;
        cin >> x;
        return x;
    };
    int len = ask2(1, n) - n * (n + 1) / 2;
    int cur = 0;
    for (int j = 19;j >= 0;j --) {
        if (cur + (1LL << j) > n) continue;
        int x = ask1(cur + (1LL << j), n);
        int y = ask2(cur + (1LL << j), n);
        if (y - x == len) cur += (1LL << j);
    }
    cout << "! " << cur << ' ' << cur + len - 1 << '\n';
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}