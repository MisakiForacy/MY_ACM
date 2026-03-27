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
1 0 0
1 1 0
1 1 1 
1 2
2 0
2 1
3
*/

// 2^3 8

void solve() {
    LL x, k;
    cin >> x >> k;
    vector<LL> a(x + 1);
    int p = 1;
    for (int i = x;i >= 1;i --) {
        if (!k) break;
        if (i > 60 || k <= p2[i - 1]) {
            a[p ++] = 1;
            k -= 1;
        } else {
            int t = 1;
            while (k > p2[i - t]) {
                k -= p2[i - t];
                t ++;
            }
            k --;
            a[p ++] = t;
            i = i - t + 1;
        }
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