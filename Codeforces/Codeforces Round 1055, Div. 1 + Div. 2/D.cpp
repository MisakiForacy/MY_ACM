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
    int n, q; 
    cin >> n >> q;
    vector<int> a(n + 1, 0), p(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        LL x;
        cin >> x;
        p[i] = p[i - 1] + int(log2(x));
        a[i] = a[i - 1];
        if ((x - 1) & x) {
            a[i] ++;
            if ((x - 1) & (x - 2)) a[i] ++;
        }
    }
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] + (a[r] - a[l - 1]) / 2 << '\n';
    }
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
