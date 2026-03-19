#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int main(){
    int n;
    cin >> n;
    int k = 0;
    vector<vector<int>> mp(n+2,vector<int>(n+2,1));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            mp[i][j] = 0;
        }
    }
    int x,y;
    x = 1;
    y = 0;
    int idx = 0;
    while (k < n*n){
        // cout << k << '\n';
        while (mp[y+dy[idx]][x+dx[idx]]){
            idx ++;
            idx %= 4;
        }
        mp[y+dy[idx]][x+dx[idx]] = ++k;
        y += dy[idx];
        x += dx[idx];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            printf("%4d",mp[i][j]);
        }
        cout << '\n';
    }
}