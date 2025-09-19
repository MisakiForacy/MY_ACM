~~~cpp
// 洛谷P1216 数字三角形

#include <bits/stdc++.h>
using namespace std;
int memo[1005][1005];
vector<vector<int>>tri;

/*
    深搜带剪枝写法
*/
int dfs(int y,int x){
    int ans = tri[y][x];
    if (memo[y][x]!=-1){
        return memo[y][x];
    }
    if (tri[y+1][x]==-1){
        memo[y][x] = tri[y][x];
        return tri[y][x];
    }
    ans += max(dfs(y+1,x),dfs(y+1,x+1));
    memo[y][x] = ans;
    return ans;
}

/*
    动态规划写法
*/
int dp(int n){
    for (int i=n-1;i>=1;i--){
        for (int j=1;j<=i;j++){
            tri[i][j] += max(tri[i+1][j],tri[i+1][j+1]);
        }
    }
    return tri[1][1];
}

/*
 相同之处：就当前数而言，都会取接下去一行中左右两个数较大的那一个
 不同之处：dfs是通过自顶向下查找，但会花费大量的时间，有些数会被重复多次查找
        可以通过记忆化搜索对其进行优化。而dp则是自底向上查找，在写dfs的时候，我们
        不难发现，上层的数无法对下层的数产生影响，下层的数决定了上层数的大小，那么，
        我们可以自底向上递推，依次更新上一层的数，最终得到最顶端的数，即为答案。
*/

int main(){
    memset(memo,-1,sizeof(memo));
    int n;
    cin >> n;
    tri.resize(n+2,vector<int>(n+2,-1));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cin >> tri[i][j];
        }
    }
    cout << dfs(1,1) << '\n';
    cout << dp(n) << '\n';
}
~~~