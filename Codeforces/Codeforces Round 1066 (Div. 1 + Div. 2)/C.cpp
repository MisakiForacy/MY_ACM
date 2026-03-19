#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve () {
    LL n, k, q;
    cin >> n >> k >> q;
    vector<int> c(q + 1), l(q + 1), r(q + 1);
    vector<int> Min(n + 2, 0), Mex(n + 2, 0);
    vector<int> Ans(n + 1, -1);
    for (int i = 1;i <= q;i ++) {
        cin >> c[i] >> l[i] >> r[i];
        if (c[i] == 1) {
            for (int j = l[i];j <= r[i];j ++) {
                Min[j] = 1;
            }
        } else {
            for (int j = l[i];j <= r[i];j ++) {
                Mex[j] = 1;
            }
        }
    }
    int use = 0;
    for (int i = 1;i <= n;i ++) {
        if (Min[i] &&  Mex[i]) Ans[i] = k + 1;
        else if (Min[i] && !Mex[i]) Ans[i] = k;
        else if (Mex[i] &&  Ans[i] == -1) {
            use = (use + 1) % k;
            Ans[i] = use;
        } 
    }
    for (int i = 1;i <= n;i ++) cout << (Ans[i] == -1 ? 0 : Ans[i]) << ' ';
    cout << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}