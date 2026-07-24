#include <bits/stdc++.h>

#define x first 
#define y second 

using namespace std;
using LL = long long;

struct Point 
{
    double x, y;
};

double cross(double x1, double y1, double x2, double y2) { 
    return x1 * y2 - x2 * y1; 
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].x >> p[i].y;
    double dir = 1.0 * (p[1].x - p[0].x) / (p[1].y - p[0].y);
    for (int i = 1;i < n;i ++) {

    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}