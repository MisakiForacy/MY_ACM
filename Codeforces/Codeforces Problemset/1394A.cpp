#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    vector<LL> a, b;
    for (int i = 1;i <= n;i ++) {
        int x;
        cin >> x;
        if (x >= m) {
            b.push_back(x);
        } else {
            a.push_back(x);
        }
    }
    sort(all(a)), sort(all(b), greater());
    int l1 = 0, r1 = siz(a) - 1, l2 = 0, r2 = siz(b) - 1;
    LL ans = 0;
    while (l1 <= r1 && l2 <= r2) {
        if (l2 <= r2) {
            
        }
    }
}