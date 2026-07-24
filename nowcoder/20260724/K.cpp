#include <bits/stdc++.h>

#define x first 
#define y second 

using namespace std;
using LL = long long;

#define double long double

struct Point 
{
    double x, y;
};


void solve() {
    int n;
    cin >> n;
    vector<pair<LL, LL>> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].x >> p[i].y;
    for (int i = 2;i < n;i ++) {
        // double t1 = atan2(p[i].x - p[i - 2].x, p[i].y - p[i - 2].y);
        // double t2 = atan2(p[i].x - p[i - 1].x, p[i].y - p[i - 1].y);
        LL dx1 = p[i].x - p[i - 1].x;
        LL dx2 = p[i].x - p[i - 2].x;
        LL dy1 = p[i].y - p[i - 1].y;
        LL dy2 = p[i].y - p[i - 2].y;
        LL cross = dx1 * dy2 - dy1 * dx2;
        if (cross == 0) {
            cout << "STRAIGHT ";
        } else if (cross < 0) {
            cout << "LEFT ";
        } else {
            cout << "RIGHT ";
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}