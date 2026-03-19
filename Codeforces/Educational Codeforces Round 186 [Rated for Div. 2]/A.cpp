#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, ok = 0, Mi = n;
    for (int i = 0;i < n - 3;i ++) {
        if (s.substr(i, 4) == "2026") ok = 1;
    }
    for (int i = 0;i < n - 3;i ++) {
        if (s.substr(i, 4) == "2025" && !ok) cnt += 1, ok = 1;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}