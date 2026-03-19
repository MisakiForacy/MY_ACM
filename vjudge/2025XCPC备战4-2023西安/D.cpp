#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define x first 
#define y second  
using namespace std;
using LL = long long;

/*
2
4
8 2 7 10
6
9 6 5 3 4 8
*/

void solve() {
    int n;
    cin >> n;
    cout << 1 << ' ';
    for (int i = 1;i < n;i ++){
        cout << "-1 2 ";
    }
    cout << (n - 2) * 2 + 1 << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(20);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}