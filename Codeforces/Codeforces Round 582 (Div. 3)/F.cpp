#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5 + 10;

LL f[N], siz[N];

void init(){
    for (int i = 0;i <= 2e5;i ++) f[i] = i;
    for (int i = 0;i <= 2e5;i ++) siz[i] = 1;
}

int findx(int x){
    if (x != f[x]){
        f[x] = findx(f[x]);
    }
    return f[x];
}

struct node{
    LL u, v, w;
    bool operator < (const node & that) const {
        return w < that.w;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<node> a(n - 1);
    init();
    for (int i = 0;i < n - 1;i ++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    vector<LL> ans(N, 0);
    sort(a.begin(), a.end());
    for (int i = 0;i < n - 1;i ++){
        int u = findx(a[i].u);
        int v = findx(a[i].v);
        ans[a[i].w] += siz[u] * siz[v];
        // merge(u, v);
        f[u] = v, siz[v] += siz[u];
    }
    for (int i = 1;i < N;i ++) ans[i] += ans[i - 1];
    while (m --){
        int x;
        cin >> x;
        cout << ans[x] << ' ';
    }
    cout << '\n';
}