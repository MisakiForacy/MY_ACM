#include <bits/stdc++.h>

#define x first 

#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;

using LL = long long;

const LL inf = 1e16;

void solve() {
    LL n, x, sum = 0;
    cin >> n >> x;
    vector<LL> a(n);
    multiset<int> p;
    for (int i = 0;i < n;i ++)
        cin >> a[i], sum += a[i];
    LL Xor = 0;
    for (int i = 0;i < n;i ++) Xor ^= a[i];
    if (Xor && lowbit(Xor) <= x) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T = 1;
    cin >> T;
    while (T --) solve();
}

// 1 R
// 2 Y
// 2 R
// 1 G
// 1 Y
// 2 B
// 2 G
// 1 B