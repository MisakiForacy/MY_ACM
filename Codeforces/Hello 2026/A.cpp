#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    int ok = 1;
    if (a[0] == 0 && a[n - 1] == 0) ok = 0;
    cout << (ok ? "Alice\n" : "Bob\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}