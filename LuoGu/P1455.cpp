#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e4+10;
int main(){
    vector<int> Set(N,0),c(N,0),d(N,0);
    auto init = [&](int n) -> void{
        for (int i=0;i<=n;i++){
            Set[i] = i;
        }
    };
    auto findx = [&](auto &findx,int x) -> int{
        if (Set[x] != x){
            int fa = Set[x];
            Set[x] = findx(findx,Set[x]);
            c[x] += c[fa];
            d[x] += d[fa];
        }
        return Set[x];
    };
    auto merge = [&](int a,int b) -> void{
        b = findx(findx,b);
        a = findx(findx,a);
        if (a > b){
            swap(a,b);
        }
        if (a != b){
            Set[b] = a;
            c[a] += c[b];
            d[a] += d[b];
        }
    };
    int n,m,w,u,v;
    cin >> n >> m >> w;
    init(n+1);
    for (int i=1;i<=n;i++){
        cin >> c[i] >> d[i];
    }
    for (int i=0;i<m;i++){
        cin >> u >> v;
        merge(u,v);
    }
    for (int i=1;i<=n;i++){
        findx(findx,i);
    }
    vector<array<int,2>> obj;
    vector<int> vis(n+1,0);
    for (int i=1;i<=n;i++){
        if (!vis[findx(findx,i)]){
            obj.push_back({c[i],d[i]});
            vis[i] = 1;
        }
    }
    vector<int> dp(w+1,0);
    for (int i=0;i<(int)obj.size();i++){
        int W = obj[i][0];
        int V = obj[i][1];
        for (int j=w;j>=W;j--){
            dp[j] = max(dp[j],dp[j-W]+V);
        }
    }
    cout << dp[w] << '\n';
}