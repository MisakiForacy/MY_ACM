#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k & 1) {
        for (int i = 0;i < k;i ++)
            cout << n << " \n"[i == k - 1];
    } else {
        vector<int> a(k, 0);
        int use = 0; // use表示数位前缀未达上限的数的个数
        for (int j = 30;j >= 0;j --) {
            if (n >> j & 1) {
                use = min(use + 1, k);
                for (int i = 0;i < use - 1;i ++) a[i] |= 1LL << j;
                for (int i = use;i < k;i ++)     a[i] |= 1LL << j;
            } else {
                for (int i = 0;i < use - (use & 1);i ++) {
                    a[i] |= 1LL << j;
                }
            }
        }
        for (int i = 0;i < k;i ++) 
            cout << a[i] << " \n"[i == k - 1];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}