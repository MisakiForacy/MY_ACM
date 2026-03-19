#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>mp(n+2,vector<int>(n+2,0));
    int x1,y1,x2,y2;
    while (m--){
        cin >> x1 >> y1 >> x2 >> y2;
        mp[x1][y1] ++;
        mp[x1][y2+1] --;
        mp[x2+1][y1] --;
        mp[x2+1][y2+1] ++;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            mp[i][j] = mp[i][j]+mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
            cout << mp[i][j] << " \n"[j==n];
        }
    }
}