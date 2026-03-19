#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int dp[2][N];
int mp[2][N];
int dfs(int mp[2][N],int y,int x,int n){
    if (x || y) x ++;
    if (y==1 && x==n-1) return 1;
    if (dp[y][x])return dp[y][x];
    if (mp[y][x+1]==1){
        int ans = dfs(mp,y,x+1,n);
        dp[y][x] = ans;
        return ans;
    }
    if (mp[(y+1)%2][x]==1){
        int ans = dfs(mp,(y+1)%2,x,n);
        dp[y][x] = ans;
        return ans;
    }
    return 0;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        getchar();
        for (int i=0;i<2;i++)
            for (int j=0;j<n;j++)
                dp[i][j] = 0;
        for (int i=0;i<n;i++){
            mp[0][i] = (getchar()=='>');
        }
        getchar();
        for (int i=0;i<n;i++){
            mp[1][i] = (getchar()=='>');
        }
        if (dfs(mp,0,0,n)){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}