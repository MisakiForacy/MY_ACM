#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

void solve() {
    int n, h, l;
    cin >> n >> h >> l;
    if (h < l) swap(h, l);
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int Cnt = 0, use = 0;
    for (int i = n;i >= 1;i --) {
        if (a[i] > h) a.pop_back();
        else if (a[i] > l) Cnt ++;
        else use ++;
    }
    if (Cnt > use) {
        cout << use << '\n';
    } else {
        cout << (Cnt + use) / 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}