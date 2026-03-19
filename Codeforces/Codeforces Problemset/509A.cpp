#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> mp(n+1,vector<int>(n+1,0)); 
    mp[1][0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            mp[i][j] = mp[i-1][j] + mp[i][j-1];
        }
    }
    cout << mp[n][n] << '\n';
}