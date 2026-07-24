#include <bits/stdc++.h>

#define x first 

#define y second 

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<LL> p(n + 1);
    vector<vector<LL>> p2(60, vector<LL> (4, 0));
    for (int i = 1;i <= n;i ++) {
        cin >> p[i];
        for (int j = 30;j >= 0;j --) {
            p2[j][(p[i] >> j) % 4] ++;
        }
    } 
    int m;
    cin >> m;
    while (m --) {
        LL op, x;
        cin >> op >> x;
        for (int j = 30;j >= 0;j --) {
            int d = (x >> j) % 4;
            for (int t1 = 0;t1 < 4;t1 ++) {
                for (int t2 = 0;t2 < 4;t2 ++) {
                    LL tmp = p2[j][t1];
                    if (op == 1) {
                        LL nu = tmp & t2;
                        
                    } else if (op == 2) {
                        LL nu = tmp | t2;
                        
                    } else {
                        LL nu = tmp ^ t2;
                        
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}