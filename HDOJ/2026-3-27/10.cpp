#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

const LL inf = 1e15;

vector<LL> p2(64, 1);

void init() {
    for (int i = 1;i <= 63;i ++) p2[i] = p2[i - 1] * 2;
}

/*
0
1 0
1 1 0
1 1 1 0 
1 1 1 1
1 1 2 0
1 2 0
1 2 1
1 3 0
2 0
2 1 0
2 1 1
2 2 0 
3 0
3 1 0
4 0
*/

void solve() {
    LL x, k;
    cin >> x >> k;
    vector<LL> a(x + 1);
    int p = 1;
    for (int i = x;i >= 1;i --) {

    }
    for (int i = 1;i < p;i ++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}