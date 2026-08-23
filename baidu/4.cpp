#include <bits/stdc++.h>

using namespace std;

using LL = long long;

using PLL = pair<LL, LL>;

const int N = 1505;

LL w[N][N], a[N][N], f[N], sz[N];

struct edge
{
    LL u, v, w;
    bool operator < (const edge&T) const {
        return T.w > w;
    }
};

void init() {
    for (int i = 0;i < N;i ++) 
        f[i] = i, sz[i] = 1;
}

int find(int x) {
    return (f[x] )
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n - i + 1;j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            for (int l = 1;l <= i;l ++) {
                for (int r = i;r <= j - 1;r ++) {
                    w[i][j] += a[l][r];
                }
            }
            for (int l = i + 1;l <= j;l ++) {
                for (int r = j;r <= n;r ++) {
                    w[i][j] += a[l][r];
                }
            }
        }
    }
    vector<edge> p;
    for (int i = 1;i <= n;i ++) {
        for (int j = i + 1;j <= n;j ++) {
            cout << w[i][j] << ' ';
            p.push_back({i, j, w[i][j]});
        }
        cout << '\n';
    }
    sort(p.begin(), p.end());
    for (int i = 0;i < p.size();i ++) {
        LL u = p[i].u, v = p[i].v, w = p[i].w;
        

    }
}

int main() {
    init();
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}