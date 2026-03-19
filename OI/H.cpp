#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<int, int>;

const double PI = 3.14159265358979323846;

const int N = 1e6 + 1;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct edge
{
    LL u, v, w;
    bool operator < (const edge&T) const {
        return w < T.w;
    }
};

inline int read(){//快读
	int x=0,y=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')y=-y; ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*y;
}

int n, m;
int Mp[1001][1001], col[1001][1001], f[N], sz[N];
vector<edge> P;
unordered_map<int, unordered_map<int, int>> g;
unordered_map<int, int> Sz;

inline void dfs(int x, int y, int c) {
    col[x][y] = c;
    Sz[c] ++;
    for (int k = 0;k < 4;k ++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!(1 <= nx && nx <= n && 1 <= ny && ny <= n)) continue;
        if (col[nx][ny]) {
            if (col[nx][ny] != c && !g[c].count(col[nx][ny])) {
                g[c][col[nx][ny]] = g[col[nx][ny]][c] = 1;
                P.push_back({c, col[nx][ny], abs(Mp[x][y] - Mp[nx][ny])});
            }
            continue;
        }
        if (Mp[nx][ny] != Mp[x][y]) continue;
        dfs(nx, ny, c);
    }
}

inline int find(int x) {
    if (f[x] != x) 
        f[x] = find(f[x]);
    return f[x];
}

inline void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (Sz[u] > Sz[v]) swap(u, v);
    f[u] = v;
    sz[v] += sz[u];
}

void solve() {
    // scanf("%d", &n);
    n = read();
    m = (n * n + 1) / 2;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            // scanf("%d", &Mp[i][j]);
            Mp[i][j] = read();
        }
    }
    int cnt = 1;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j <= n;j ++) {
            if (!col[i][j]) {
                dfs(i, j, cnt ++);
            }
        }
    }
    for (int i = 1;i < cnt;i ++) f[i] = i, sz[i] = Sz[i];
    sort(all(P));
    for (int i = 0;i < siz(P);i ++) {
        int u = P[i].u, v = P[i].v, w = P[i].w;
        if (find(u) == find(v)) continue;
        merge(u, v);
        if (sz[find(u)] >= m) {
            printf("%d", w);
            return;
        }
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}