#include <bits/stdc++.h>

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    LL n, t, S;
    cin >> n >> t >> S;
    cout << (n * ((1LL << t) - 1) >= S ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}