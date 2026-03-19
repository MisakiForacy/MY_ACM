#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;

mt19937_64 rnd(time(0));

void solve() {
    int n, k;
    cin >> n >> k;
    vector<map<char, int>> p(k + 1);
    for (int i = 1;i <= k;i ++) {
        for (int j = 1;j <= n;j ++) {
            char c;
            cin >> c;
            p[i][c] ++;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}