#include <bits/stdc++.h>

#define x first 
#define y second 

#define LOG 30

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    LL X = 0;
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    int fi = 1, se = 2;
    vector<int> use(n + 1, 0);
    use[fi] = use[se] = 1;
    auto add = [&](int x) -> int {
        x += 1;
        while (use[x]) x ++;
        return x;
    };
    for (int i = 1;i <= n - 2;i ++) {
        if (a[fi] >= 0 && a[se] >= 0) {
            X += a[fi];
            use[fi] = 1;
            se = add(se);
            fi = add(fi);
        } else if (a[fi] >= 0 && a[se] < 0) {
            X -= a[se];
            use[se] = 1;
            se = add(se);
        } else if (a[fi] < 0 && a[se] < 0) {
            X -= a[se];
            use[se] = 1;
            se = add(se);
        } else if (a[fi] < 0 && a[se] >= 0) {
            if (abs(a[fi]) < abs(a[se])) {
                X += a[fi];
                use[fi] = 1;
                se = add(se);
                fi = add(fi);
            } else {
                X -= a[se];
                use[se] = 1;
                se = add(se);
            }
        }
    }
    LL Ans = 0;
    Ans = max(X + a[fi], X - a[se]);
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}