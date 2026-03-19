#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e6+10;
const int MOD = 1e9+7;
int Set[N];
void init(int n){
    for (int i=0;i<=n;i++){
        Set[i] = i;
    }
}
int findx(int x){
    if (Set[x] != x) {
        Set[x] = findx(Set[x]);
    }
    return Set[x];
}
void merge(int a,int b){
    Set[findx(b)] = findx(a);
}
LL qpow(LL a,LL k){
    LL res = 1;
    while (k){
        if (k&1) res = res * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        string s;
        init(2*n+1);
        vector<vector<int>> G(m+1);
        vector<vector<int>> g(n+1);
        vector<vector<int>> mp(n+1,vector<int> (m+1,0));
        for (int i=1;i<=n;i++){
            cin >> s;
            for (int j=1;j<=m;j++){
                mp[i][j] = s[j-1] == '1';
                if (s[j-1] == '1'){
                    G[j].push_back(i);
                    G[m-j+1].push_back(i);
                    g[i].push_back(j);
                    g[i].push_back(m-j+1);
                }
            }
        }
        int ok = 1;
        for (int i=1;i<=m;i++){
            if (G[i].size() > 2){
                ok = 0;
                break;
            }
        }
        if (ok){
            for (int i=1;i<=n;i++){
                for (auto k:g[i]){
                    for (auto j:G[k]){
                        if (i == j) continue;
                        if (mp[i][k] == mp[j][k]){
                            merge(i,j+n);
                            merge(i+n,j);
                        } else{
                            merge(i,j);
                            merge(i+n,j+n);
                        }
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            if (findx(i) == findx(i+n)){
                ok = 0;
                break;
            }
        }
        set<int> a;
        for (int i=1;i<=2*n;i++){
            a.insert(findx(i));
        }
        if (ok){
            cout << qpow(2,a.size()/2) << '\n';
        } else{
            cout << 0 << '\n';
        }
    }
}