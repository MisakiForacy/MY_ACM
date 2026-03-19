#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,mx = 0;
    cin >> n;
    vector<vector<int>>mp(n+1,vector<int>(n+1));
    vector<vector<int>>pre(n+1,vector<int>(n+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> mp[i][j];
            pre[i][j] = mp[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    for (int x1=1;x1<=n;x1++)
    for (int x2=x1;x2<=n;x2++)
    for (int y1=1;y1<=n;y1++)
    for (int y2=y1;y2<=n;y2++){
        int sum = pre[y2][x2]-pre[y1-1][x2]-pre[y2][x1-1]+pre[y1-1][x1-1];
        mx = max(mx,sum);
    }
    cout << mx << '\n';
}