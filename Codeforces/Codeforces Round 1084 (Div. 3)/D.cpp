#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1), out, in;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= x;i ++) out.push_back(a[i]);
    for (int i = x + 1;i <= y;i ++) in.push_back(a[i]);
    for (int i = y + 1;i <= n;i ++) out.push_back(a[i]);
    vector<int> in1;
    int mi = n + 1, id = -1;
    for (int i = 0;i < siz(in);i ++) {
        if (in[i] < mi) {
            mi = in[i];
            id = i;
        }
    }
    for (int i = id;i < siz(in);i ++) in1.push_back(in[i]);
    for (int i = 0;i < id;i ++) in1.push_back(in[i]);
    vector<int> ans;
    int ok = 0;
    for (int i = 0;i < siz(out);i ++) {
        if (in1[0] < out[i] && !ok) {
            ok = 1;
            for (int x : in1) ans.push_back(x);
            ans.push_back(out[i]);
        } else {
            ans.push_back(out[i]);
        }
    }
    if (!ok) for (int x : in1) ans.push_back(x);
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}