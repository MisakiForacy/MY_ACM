#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cerr << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int N = 2e5 + 10;
const LL inf = 1e15;
const int P = 131;

mt19937_64 rng(time(0));

void fxy_ac() {
    int n;
    cin >> n;
    vector<LL> a(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL Max = 0, ans = 0;
    for (int i = 1;i <= n;i ++) {
        Max = max(Max, a[i]);
        if (!(i & 1)) a[i] = Max;
    }
    for (int i = 1;i <= n;i ++) {
        if (!(i & 1) && (a[i] <= a[i - 1] || a[i] <= a[i + 1])) {
            ans += max({0LL, a[i - 1] - a[i] + 1});
            ans += max({0LL, a[i + 1] - a[i] + 1});
            a[i - 1] -= max({0LL, a[i - 1] - a[i] + 1});
            a[i + 1] -= max({0LL, a[i + 1] - a[i] + 1});
        }
    }
    cout << ans << '\n';
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}