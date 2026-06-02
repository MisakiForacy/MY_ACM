#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<LL, LL>> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].x >> p[i].y;
    LL lo = 0, hi = 1000000;
    auto check = [&](int pos) -> LL {
        LL sum = 0;
        for (int j = 0;j < n;j ++) {
            if (p[j].x <= pos && pos <= p[j].y) continue;
            sum += min((p[j].x - pos) * (p[j].x - pos), (p[j].y - pos) * (p[j].y - pos));
        }
        return sum;
    };
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid) <= check(mid + 1)) 
            hi = mid;
        else    
            lo = mid + 1;
    }
    cout << check(lo) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
