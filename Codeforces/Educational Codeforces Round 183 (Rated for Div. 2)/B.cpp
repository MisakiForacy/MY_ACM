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
    LL n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) a[i] = i;
    vector<char> ans(n + 1, '+');
    int ok = 0;
    LL lo = 1, hi = n, cnt = 0;
    for (int i = 1;i <= k;i ++) {
        char x;
        cin >> x;
        if (x == '0') {
            ans[lo ++] = '-';
        } else if (x == '1') {
            ans[hi --] = '-';
        } else {
            cnt ++;
        }
    }
    for (int i = 1;i <= cnt;i ++) {
        ans[lo ++] = ans[hi --] = '?';
    }
    if (k >= n) {
        for (int i = 1;i <= n;i ++) cout << '-';
        cout << '\n';
        return;
    }
    for (int i = 1;i <= n;i ++) cout << ans[i];
    cout << '\n';
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