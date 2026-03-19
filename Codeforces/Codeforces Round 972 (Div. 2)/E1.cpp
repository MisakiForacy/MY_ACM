#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,n,m;
ll dfs(vector<int> a,vector<vector<int>> mp,int r,int c,int k){
    if (k>=l || c>m || r>n){
        return 0;
    }
    if (c==n && r==m){
        if (mp[r][c]==a[k]){
            return 1;
        } else{
            return 0;
        }
    }
    for (int i=n;i>=r;i--){
        for (int j=m;j>=c;j--){
            if (mp[i][j] == a[k]){
                return 1 + dfs(a,mp,i+1,j+1,k+1);
            }
        }
    }
    return 0;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        cin >> l >> n >> m;
        vector<int> a(l);
        vector<vector<int>> mp(n+1,vector<int>(m+1,0));
        for (int i=0;i<l;i++) cin >> a[i];
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cin >> mp[i][j];
            }
        }
        cout << ((dfs(a,mp,1,1,0)&1)?"T\n":"N\n");
    }
}