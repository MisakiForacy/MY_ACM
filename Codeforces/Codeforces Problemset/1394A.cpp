#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    vector<LL> a(n + 1), p(n + 1, 0), p1(1, 0);
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end(), greater());
    for (int i = 1;i <= n;i ++) if (a[i] < m) p1.push_back(p1.back() + a[i]);
    int t = siz(p1) - 1;
    for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + a[i];
    LL ans = 0;
    for (int i = 0;i < n;i ++) {
        if (a[i] < m) break;
        LL val = 0;
        val += (p[n] - p[i - 1]) 
    }
}