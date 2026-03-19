#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
 
using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    LL n;
    cin >> n;
    int N = 1LL << n;
    for (int i = 0;i < N;i ++) {
        cout << (i ^ (i >> 1)) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}