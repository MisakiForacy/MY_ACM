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
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    unordered_set<LL> ans, cur;
    for (int j = 1;j <= n;j ++) {
        unordered_set<LL> nxt;
        nxt.insert(a[j]);
        for (auto x : cur) {
            nxt.insert(x & a[j]);
            nxt.insert(x | a[j]);
            nxt.insert(x ^ a[j]);
        }
        for (auto x : nxt) ans.insert(x);
        cur = move(nxt);
    }
    cout << siz(ans) << "\n";
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}