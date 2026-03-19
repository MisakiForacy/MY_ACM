#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const double eps = 1e-9;

struct Point
{
    LL x, y;
    bool operator < (const Point&that) const { return x > that.x;}
    Point(LL _x = 0,LL _y = 0) {this->x = _x, this->y = _y;}
    Point operator + (const Point &b) const { return Point(x + b.x, y + b.y);}
    Point operator - (const Point &b) const { return Point(x - b.x, y - b.y);}
    LL operator * (const Point &b) const { return x * b.x + y * b.y;}
    LL operator ^ (const Point &b) const { return x * b.y - b.x * y;}
};

typedef Point Vector;

vector<Point> p;

int check (Point a, Point b, Point c) {
    Vector A = a - b;
    Vector B = c - a;
    double cross = A ^ B;
    return cross >= 0;
}

map<pair<int, int>, int> mp;

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        LL x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    for (int i = 0;i < n;i ++) {
        int L = (i - 1 + n) % n;
        mp[{L, i}] = 1;
    }
    int ans = 0;
    vector<int> use(n, 0), opend(n, 0);
    for (int i = 0;i < n;i ++) {
        int L = (i - 1 + n) % n, R = (i + 1) % n;
        int Lup = 0, Rup = 0, Lopen = 0;
        while (1) {
            if (opend[L]) { open = 1; break;}
            if (p[L].y > p[i].y) { Lup = 1; break;}
            if (p[L].y < p[i].y) { Ldown = 1; break;}
            L = (L - 1 + n) % n;
        } 
        if (open || Ldown) continue;
        while (1) {
            if (opend[R]) { open = 1; break;}
            if (p[R].y > p[i].y) { Rup = 1; break;}
            if (p[R].y < p[i].y) { Rdown = 1; break;}
            R = (R + 1) % n;
        }
        if (open || Rdown) continue;
        if (Lup && Rup) {
            if (check(p[i], p[L], p[R]) || (L == R)) {
                opend[i] = 1;
            }
        }
    }
    for (int i = 0;i < n;i ++) ans += opend[i];
    cout << ans << '\n';
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.tix", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}