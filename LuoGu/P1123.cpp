#include <bits/stdc++.h>
#define N 10
using namespace std;
typedef long long i64;
i64 t,n,m;
i64 matrix[N][N];
bool ss[N][N];
void solve();
i64 dfs(int y,int x);
bool check(int y,int x);
int main(){
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> n >> m;
    memset(ss,0,sizeof(ss)), memset(matrix,0,sizeof(matrix));
    for(int i=1;i <= n; i ++){
        for(int j=1; j <= m; j ++){
            cin >> matrix[i][j];
        }
    }
    cout << dfs(1,1) << endl;
}
i64 dfs(int y,int x){
    i64 maxn = 0;
    ss[y][x]=ss[y-1][x-1]=ss[y-1][x]=ss[y-1][x+1]=ss[y][x-1]=ss[y][x+1]=ss[y+1][x-1]=ss[y+1][x]=ss[y+1][x+1]=1;
    maxn += matrix[y][x];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check(i,j)){
                maxn = max(maxn,dfs(i,j));
                ss[y][x]=ss[y-1][x-1]=ss[y-1][x]=ss[y-1][x+1]=ss[y][x-1]=ss[y][x+1]=ss[y+1][x-1]=ss[y+1][x]=ss[y+1][x+1]=0;
            }
        }
    }
    return maxn;
}
bool check(int y,int x){
    return ss[y-1][x-1]+ss[y-1][x]+ss[y-1][x+1]+ss[y][x-1]+ss[y][x+1]+ss[y+1][x-1]+ss[y+1][x]+ss[y+1][x+1];
}