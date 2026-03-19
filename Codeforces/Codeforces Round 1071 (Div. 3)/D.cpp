#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p;
    int num = n, cnt = 1;
    while (siz(p) < (1LL << n)) {
        cnt *= 2;
        LL x = 0, j;
        for (j = 0;j < num;j ++) x += 1LL << j;
        j ++;
        while (x < (1LL << n)) {
            p.push_back(x);
            x += 1LL << j;
        }
        num -= 1;
    }
    for (int x : p) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T --) solve();
}