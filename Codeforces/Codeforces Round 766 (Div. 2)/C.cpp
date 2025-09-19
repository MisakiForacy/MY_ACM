#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define x first
#define y second
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

struct edge{
    int u, v, id;
};

struct node{
    int v, id;
};

vector<node> g[N];
vector<int> vis;

void dfs(int pu, int u, int e, vector<int> &a){
    for (auto [v, id] : g[u]){
        if (v == pu) continue;
        a[id] = (e ? 2 : 3);
        dfs(u, v, !e, a);
    }
}

void fxy_ac(){
    int n;
    cin >> n;
    for (int i = 0;i <= n;i ++) g[i].clear();
    vector<edge> p(n);
    vector<int> in(n + 1, 0), a(n, 0), c(n, 0);
    for (int i = 1;i < n;i ++){
        cin >> p[i].u >> p[i].v;
        g[p[i].u].push_back({p[i].v, i});
        g[p[i].v].push_back({p[i].u, i});
        in[p[i].u] ++, in[p[i].v] ++;
    }
    int st;
    for (int i = 1;i <= n;i ++){
        if (in[i] > 2){
            cout << -1 << '\n';
            return;
        }
        if (in[i] == 1){
            st = i;
        }
    }
    dfs(0, st, 0, a);
    for (int i = 1;i < n;i ++){
        cout << a[i] << " \n"[i == n - 1];
    }
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T; // 多测
    while (T --){
        fxy_ac();
        // brute();
    }
}