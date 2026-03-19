#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
dfs()
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,k;
        cin >> n >> m >> k;
        vector mp(n+2,vector<int>(m+2,0));
        for (int i=1;i<=n;i++){
            cin >> s;
            for (int j=1;j<=m;j++){
                mp[i][j] = (s[j-1]=='0');
            }
        }
        cout << dfs(mp) << '\n';
    }
}