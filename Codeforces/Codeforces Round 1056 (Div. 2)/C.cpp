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
const int MOD = 676767677;

LL qmi(LL a, LL k) {
    LL res = 1;
    while (k) {
        if (k & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        k >>= 1;
    }
    return res;
}

void init() {
    
}

void fxy_ac() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    // vector<LL> L(n + 1, 0), R(n + 1, 0);
    // for (int i = 1;i <= n;i ++) R[i] = n - i + 1;
    LL ans = 0;
    // LL v1 = a[1], v2 = a[1] - 1;
    for (int i = a[1];i >= a[1] - 1;i --) {
        if (0 <= i && i <= n) {
            LL pre = 0, ok = 1;
            for (int j = 1;j <= n;j ++) {
                int val = j + i - a[j] - pre;
                if (val < 0 || val > n) {
                    ok = 0;
                    break;
                }
                if (val < pre || val > pre + 1) {
                    ok = 0;
                    break;
                }
                pre = val;
            }
            if (ok && pre == i) ans += 1;
        }
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