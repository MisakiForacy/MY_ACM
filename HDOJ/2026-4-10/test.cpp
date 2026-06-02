#include<bits/stdc++.h>
using namespace std;
int a[10000], mp[20][20];
int main(){
    // freopen("seat.in","r",stdin);
    // freopen("seat.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < n * m;i ++) cin >> a[i];
    int v = a[0];
    sort(a, a + n * m, greater());
    int x = 1, y = 1, f1 = 1, f2 = 0, t = 1;
    if (n == 1) f2 = 1, f1 = 0;
    for (int i = 0;i < n * m;i ++) {
        mp[x][y] = a[i];
        x += f1, y += f2;
        if (n > 1) {
            if (x == n && t == 1) {
                f1 = 0;
                f2 = 1;
                t = -t;
            } else if (x == n && f2 == 1) {
                f1 = t;
                f2 = 0;
            } else if (x == 1 && t == -1) {
                f1 = 0;
                f2 = 1;
                t = -t;
            } else if (x == 1 && f2 == 1) {
                f1 = t;
                f2 = 0;
            }
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= m;j ++) {
            if (mp[i][j] == v) {
                cout << j << ' ' << i << '\n';
                return 0;
            }
        }
    }
}