#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>>cnt(n,vector<int>(m));
    for (int i=0;i<n;i++) cin >> a[i];
    for (int y=0;y<n;y++){
        for (int x=0;x<m;x++){
            vector<int> dp(x+2,0);
            for (int i=0;i<n;i++){
                if (i!=y){
                    for (int j=x+1;j>=a[i];j--){
                        dp[j] = max(dp[j],dp[j-a[i]]+1);
                    }
                }
            }
            cnt[y][x] = dp[x+1];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=m-1;j>=0;j--){
            cout << cnt[i][j];
        }
        cout << '\n';
    }
}