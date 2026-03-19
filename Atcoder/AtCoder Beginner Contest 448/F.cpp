#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 1e4 + 7;

struct node
{
    LL x, y, id;
    bool operator < (const node&T) const {
        if (x != T.x) return T.x < x;
        return T.y < y;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].x >> p[i].y, p[i].id = i;
    LL x = p[0].x, y = p[0].y;
    sort(all(p));
    map<LL, vector<LL>> X;
    for (int i = 0;i < n;i ++) X[p[i].x].push_back(p[i].y);
    int ok = 0;
    for (auto [xx, v] : X) {
        if (ok) {

        }
        if (xx == x) {

        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}