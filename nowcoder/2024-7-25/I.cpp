#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>>mp,int lo,int hi){
    for (int i=lo;i<hi;i++){
        if (!mp[i][hi]) return 0;
    }
    return 1;
}
int main(){
    int n,m,u,v;
    cin >> n >> m;
    vector<vector<int>>mp(n+1,vector<int>(n+1,0));
    for (int i=0;i<m;i++){
        cin >> u >> v;
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    for (int i=1;i<=n;i++){
        mp[i][i] = 1;
    }
    int lo = 1, hi = 1;
    for (hi = 1; hi <= n;hi ++){
        
    }
}