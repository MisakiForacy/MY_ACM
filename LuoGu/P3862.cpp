#include <bits/stdc++.h>
#define N 1010
using namespace std;
typedef long long i64;
i64 n,m,u,v,ptr,maxn;
i64 G[N];
struct info{
    int u,v;
}a[N];
bool cmp(const info &a, const info &b){
    return a.u < b.u;
}
void solve();
int main(){
    solve();
    return 0;
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= N; i ++){
        G[i] = i;
    }
    for(int i = 0; i < m; i ++){
        cin >> a[i].u >> a[i].v;
    }
    sort(a,a + m,cmp);
    for(int i = 0; i < m; i ++){
        u = a[i].u, v = a[i].v;
        for(int j = 1; j <= n; j ++){
            if((G[j] == u || u == j) && G[v] > G[j]){
                G[j] = G[v];
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        cout << G[i] << " ";
    }
    return;
}