#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>mp(n+1,vector<int>(m+1));
    vector<vector<int>>pre(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> mp[i][j];
            pre[i][j] = mp[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    int q;
    int a,b,c,d;
    cin >> q;
    while (q--){
        cin >> a >> b >> c >> d;
        cout << pre[a][b] - pre[c][b] - pre[a][d] + pre[c][d] << '\n';
    }
}