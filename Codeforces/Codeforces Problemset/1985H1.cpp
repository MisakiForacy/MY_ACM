#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
void dfs(int s){

}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m;
        char c;
        cin >> n >> m;
        vector<vector<int>> mt(n+1,vector<int>(m+1,0));
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin >> c;
                mt[i][j] = (c=='#');
            }
        }
        
    }
}