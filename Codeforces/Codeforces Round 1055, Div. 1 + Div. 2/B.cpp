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
    LL n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;
    auto cal = [&](LL r, LL c) -> LL {
        return max(abs(r - rd), abs(c - cd));
    };
    LL ans = 0;
    if (rk == rd) {
        if (ck < cd) ans = cd;
        else ans = n - cd;
    } else if (ck == cd) {
        if (rk < rd) ans = rd;
        else ans = n - rd;
    } else {
        LL r = (rd > rk ? 0 : n);
        LL c = (cd > ck ? 0 : n);
        ans = cal(r, c);
    }
    cout << ans << '\n';
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