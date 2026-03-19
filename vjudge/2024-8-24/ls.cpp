#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct haha{
    int x,y1,y2;
    bool operator < (const haha &that) const {
        return x < that.x;
    }
};
int main(){
    int n;
    cin >> n;
    vector<haha> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y1 >> a[i].y2;
    }
    sort(a.begin(),a.end());
    double k2 = -inf, k1 = inf;
    for (int i=1;i<n;i++){
        double dx = a[i].x - a[0].x;
        double dy1 = a[i].y1 - a[0].y1;
        double dy2 = a[i].y2 - a[0].y2;
        k1 = min(k1,dy1 / dx);
        k2 = max(k2,dy2 / dx);
    }
    double k = (k1+k2) / 2;
    int b = a[0].y1 - a[0].x * k;
    int y2 = a.back().x * k + b;
    cout << a[0].x << ' ' << a[0].y1 << ' ' << a.back().x << ' ' << y2 << '\n';
    // cout << a[0].x << ' ' << a[0].y1 << ' ' << a.back().x << ' ' << a.back().y1 << '\n';
}