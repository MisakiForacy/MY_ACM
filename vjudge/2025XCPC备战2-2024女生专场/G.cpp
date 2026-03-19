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

const int N = 2e5 + 10;
const LL inf = 2e18;

mt19937_64 rng(time(0));

void fxy_ac() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    vector<int> ok(62, 0);
    for (int i = n - 1;i >= 1;i --) {
        for (int j = 62;j >= 0;j --) {
            if ((a[i] >> j & 1) != (a[i + 1] >> j & 1)) {
                if (a[i] >> j & 1) {
                    if (ok[j] != 2) ok[j] = 1;
                    else {
                        cout << 0 << '\n';
                        return;
                    }
                } else {
                    if (ok[j] != 1) ok[j] = 2;
                    else {
                        cout << 0 << '\n';
                        return;
                    }
                }
                break;
            }
        }
    }
    LL ans = 0;
    for (int j = 62;j >= 0;j --) {
        if (j && !(k >> j & 1)) continue;
        int okk = 0;
        for ()
    }
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