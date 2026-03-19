#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    struct node{
        string a,b;
    };
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<node> a(n+1);
        for (int i=0;i<n;i++){
            cin >> a[i].a >> a[i].b;
        }
        int con[n+1][n+1];
        memset(con,0,sizeof(con));
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (a[i].a==a[j].a || a[i].b==a[j].b){
                    con[i][j] = con[j][i] = 1;
                }
            }
        }
        int dp[n+1][(1LL << n)];
        memset(dp,0,sizeof(dp));
        for (int i=0;i<n;i++){
            dp[i][(1LL << i)] = 1;
        }
        for (int i=0;i<(1LL << n);i++){
            for (int j=0;j<n;j++){
                for (int k=0;k<n;k++){
                    if (dp[j][i] && con[j][k] && !(i & (1LL << k))){
                        dp[k][i | (1LL << k)] = 1;
                    }
                }
            }
        }
        int Max = 0;
        for (int i=0;i<(1LL << n);i++){
            for (int j=0;j<n;j++){
                if (dp[j][i]){
                    int cnt = 0;
                    for (int k=0;k<n;k++){
                        if (i & (1LL << k)){
                            cnt ++;
                        }
                    }
                    Max = max(Max,cnt);
                }
            }
        }
        cout << n - Max << '\n';
    }
}