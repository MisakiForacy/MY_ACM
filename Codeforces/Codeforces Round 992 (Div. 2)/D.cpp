#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL N = 4e5+10;
int sieve[N];
int prime[N];
int Euler(int n){
    int k = 0;
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            prime[k++] = i;
        }
        for (int j=0;j<k;j++){
            if (i * prime[j] > n) break;
            sieve[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return k;
}
int main(){
    Euler(4e5);
    vector<int> a = {1};
    for (int i=4;i<=4e5;i++){
        if (sieve[i]){
            a.push_back(i);
        }
    }
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> G[n+1];
        vector<int> vis(n+1,0);
        vector<int> ans(n+1,0);
        vector<int> use(2*n+1,0);
        int u,v,k;
        for (int i=1;i<n;i++){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        queue<int> Q;
        Q.push(1);
        ans[1] = 1, k = 1;
        while (!Q.empty()){
            int u = Q.front();
            Q.pop();
            vis[u] = 1;
            k = 0;
            for (int i=0;i<G[u].size();i++){
                if (!vis[G[u][i]]){
                    while (use[ans[u] + a[k]]) k ++;
                    ans[G[u][i]] = ans[u] + a[k++];
                    use[ans[G[u][i]]] = 1;
                    Q.push(G[u][i]);
                }
            }
        }
        for (int i=1;i<=n;i++){
            cout << ans[i] << " \n"[i==n];
        }
    }
}