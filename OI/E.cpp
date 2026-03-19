#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<int, int>;

const double PI = 3.14159265358979323846;

void solve() {
    int n, x, y, x_, y_;
    int l, r, u, d;
    cin >> n >> x >> y >> x_ >> y_;
    l = min(x, x_), r = max(x, x_);
    d = min(y, y_), u = max(y, y_);
    vector<PII> P(n); vector<int> px(n);
    for (int i = 0;i < n;i ++) px[i] = i;
    for (int i = 0;i < n;i ++) cin >> P[i].x >> P[i].y;
    auto dir = [&](PII A, PII B) -> double {
        int x1 = A.x, y1 = A.y;
        int x2 = B.x, y2 = B.y;
        double dx = abs(x2 - x1), dy = abs(y2 - y1);
        return sqrt(dx * dx + dy * dy);
    };  
    LL SS = (r - l) * (u - d);
    LL Ans = SS;
    do {
        double S = 0;
        vector<PII> put;
        vector<double> R;
        for (int i = 0;i < n;i ++) {
            int nx = P[px[i]].x, ny = P[px[i]].y;
            double rr = 5000000;
            rr = min(rr, double(abs(ny - u)));
            rr = min(rr, double(abs(ny - d)));
            rr = min(rr, double(abs(nx - l)));
            rr = min(rr, double(abs(nx - r)));
            for (int j = 0;j < siz(put);j ++) 
                rr = min(rr, dir(put[j], P[px[i]]) - R[j]);
            if (rr < 0) rr = 0;
            put.push_back(P[px[i]]);
            R.push_back(rr);
            S += PI * rr * rr;
        }
        Ans = min(Ans, SS - LL(S + 0.5));
    } while (next_permutation(all(px)));
    cout << Ans << '\n';
}
// 5 4 4 3 3 2 2 1 1
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}