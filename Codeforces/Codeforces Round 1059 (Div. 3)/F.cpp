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
    LL n, m;
    cin >> n >> m;
    vector<int> p(n + 2, 0), ans(n + 1, -1);
    map<pair<int, int>, int> vis;
    map<int, int> L, R;
    vector<pair<int, int>> pp;
    int mm = 0;
    for (int i = 1;i <= m;i ++) {
        int l, r;
        cin >> l >> r;
        if (vis.count({l, r})) continue;
        vis[{l, r}] = 1;
        pp.push_back({l, r});
        R[r] ++, L[l] ++;
        p[l] ++, p[r + 1] --;
        mm ++;
    }
    int ok = 0;
    for (int i = 1;i <= n;i ++) p[i] += p[i - 1];
    for (int i = 1;i <= n;i ++) 
        if (p[i] == mm) {
            ans[i] = 0;
            ok = 1;
            break;
        }
    if (ok) {
        int num = 1;
        for (int i = 1;i <= n;i ++)
            if (ans[i] == -1) 
                ans[i] = num ++;
        for (int i = 1;i <= n;i ++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1;i <= n;i ++) {
        if (p[i] == 0) {
            ans[i] = 0;
            ok = 1;
            break;
        }
    }
    if (ok) {
        int num = 1;
        for (int i = 1;i <= n;i ++) 
            if (ans[i] == -1)
                ans[i] = num ++;
        for (int i = 1;i <= n;i ++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (auto [k, v] : vis) {
        int l = k.x, r = k.y;
        if (r - l + 1 == 1) continue;
        for (int j = l;j <= r;j ++) {
            if (j > l && !R.count(j - 1)) {
                ans[j - 1] = 0, ans[j] = 1;
                ok = 1;
                break;
            }
            if (j < r && !L.count(j + 1)) {
                ans[j + 1] = 0, ans[j] = 1;
                ok = 1;
                break;
            }
        }
        if (ok) {
            int num = 2;
            for (int i = 1;i <= n;i ++)
                if (ans[i] == -1) 
                    ans[i] = num ++;
            for (int i = 1;i <= n;i ++) cout << ans[i] << ' ';
            cout << '\n';
            return;
        }
    }
    int num = 3;
    ans[1] = 1, ans[2] = 2, ans[3] = 0;
    for (int i = 1;i <= n;i ++)
        if (ans[i] == -1)
            ans[i] = num ++;
    for (int i = 1;i <= n;i ++) cout << ans[i] << ' ';
    cout << '\n';
    return;
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