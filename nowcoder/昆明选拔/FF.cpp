#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> mp(4,vector<int> (n+1,0));
    vector<vector<int>> dp(4,vector<int> (n+1,0));  
    for (int i=1;i<=3;i++){
        for (int j=1;j<=n;j++){
            cin >> mp[i][j];
        }
    }
    for (int i=1;i<=3;i++) dp[i][1] = mp[i][1];
    for (int i=1;i<=n;i++) dp[1][i] = mp[1][i];
    for (int i=2;i<=3;i++){
        for (int j=2;j<=n;j++){
            dp[i][j] = min(dp[i][j-1]+abs(mp[i][j]-mp[i][j-1]),dp[i-1][j]+abs(mp[i][j]-mp[i-1][j]));
        }
    }
    int x,y;
    x = n, y = 3;
    string ans = "";
    while (!(x == 1 && y == 1)){
        if (y > 1 && dp[y][x]-dp[y-1][x]==abs(mp[y][x]-mp[y-1][x])){
            ans.push_back('2');
            y --;
        } else if (x > 1){
            ans.push_back('1');
            x --;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
}