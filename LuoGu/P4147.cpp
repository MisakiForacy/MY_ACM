#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    char c;
    cin >> n >> m;
    vector<vector<int>> mat(n+2,vector<int>(m+2,1));
    vector<vector<int>> nge(n+2,vector<int>(m+2,1));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> c;
            mat[i][j] = (c=='R');
        }
    }
    for (int j=1;j<=m;j++){
        stack<int> stk;
        for (int i=n+1;i>=1;i--){
            while (!stk.empty() && mat[stk.top()][j]<=mat[i][j]){
                stk.pop();
            }
            nge[i][j] = stk.empty()?0:stk.top();
            stk.push(i);
        }
    }
    ll ans = 0;
    ll x = 0, y = LLONG_MAX;
    for (int i=1;i<=n;i++){
        for (int k=1;k<=m;k++){
            for (int j=k;j<=m;j++){
                if (mat[i][j]){
                    x = 0, y = LLONG_MAX;
                } else{
                    x ++;
                    y = min(y,ll(nge[i][j]-i));
                    ans = max(ans,x*y);
                }
            }
            x = 0, y = LLONG_MAX;
        }
    }
    cout << ans*3 << '\n';
}