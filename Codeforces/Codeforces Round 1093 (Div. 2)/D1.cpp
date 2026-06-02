#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

voiod solve() {
    int n;
    cin >> n;
    auto ask = [&](vector<int> s) -> int {
        cout << "? " << siz(s) << ' ';
        for (int x : s) cout << x << ' ';
        cout << '\n';
        int x;
        cin >> x;
        return x;
    };
    
}

int main() {
    int T = 1;
    cin >> T;
    while (T --) solve();
}