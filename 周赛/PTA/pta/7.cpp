#include <bits/stdc++.h>
using namespace std;
int n;
int tot;
vector<int>ans;
vector<vector<int>>mp;
bool check(int x,int y){
    for (int i=1;i<y;i++){
        if (abs(ans[i]-x)==abs(i-y)||ans[i]==x) return 0;
    }
    return 1;
}
int CNT = 0;
int dfs(int y,int x){
    int cnt = 0;
    mp[y][x] = 1;
    if (y==n){
        printf("%4d:",++CNT);
        for (int i=1;i<=n;i++){
            printf("%3d",ans[i]);
        }
        cout << '\n';
        return 1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            mp[y+1][j] = 0;
        }
        if (check(i,y+1)){
            if (y+1==n) tot ++;
            ans[y+1] = i;
            cnt += dfs(y+1,i);
        }
    }
    return cnt;
}
int main(){
    cin >> n;
    mp.resize(n+1,vector<int>(n+1,0));
    ans.resize(n+1,0);
    int cnt = 0;
    tot = 0;
    for (int i=1;i<=n;i++){
        mp[1][i-1] = 0;
        ans[1] = i;
        cnt += dfs(1,i);
    }
    if (CNT==0){
        cout << "no answer\n";
    }
}