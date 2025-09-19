#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac(){
    int n, k, x;
    cin >> n >> k;
    vector<LL> c(n + 1, 0), ans(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> c[i];
    for (int i = 1;i <= k;i ++){
        cin >> x;
        c[x] = 0;
    }
    vector<int> g[n + 1];
    int in[n + 1];
    memset(in, 0, sizeof(in));
    for (int i = 1;i <= n;i ++){
        int m, u;
        cin >> m;
        for (int j = 1;j <= m;j ++){
            cin >> u;
            g[u].push_back(i);
            in[i] ++;
        }
    }
    queue<int> q;
    for (int i = 1;i <= n;i ++){
        if (in[i] == 0){
            q.push(i);
            ans[i] += c[i];
        }
    }
    while (!q.empty()){
        int u = q.front();
        q.pop();
        ans[u] = min(ans[u], c[u]);
        for (auto v : g[u]){
            ans[v] += ans[u];
            if (-- in[v] == 0){
                q.push(v);
            }
        }
    }
    for (int i = 1;i <= n;i ++){
        cout << ans[i] << " \n"[i == n];
    }
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}