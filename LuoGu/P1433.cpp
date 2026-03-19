#include <bits/stdc++.h>
using namespace std;
using LL = long long;
double f(double fx,double fy,double sx,double sy){
    return sqrt((fx-sx)*(fx-sx)+(fy-sy)*(fy-sy));
}
int main(){
    struct coord{
        double x,y;
    };
    int n;
    cin >> n;
    vector<coord> a(n+1);
    for (int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
    }
    vector<vector<double>> dp(n+1,vector<double>(1LL << n,INT_MAX));
    for (int i=0;i<n;i++){
        dp[i][(1LL << i)] = f(0,0,a[i].x,a[i].y);
    }
    for (int i=0;i<(1LL << n);i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                dp[k][i | (1LL << k)] = min(dp[k][i | (1LL << k)],dp[j][i] + f(a[j].x,a[j].y,a[k].x,a[k].y));
            }
        }
    }
    double ans = 1000000.0;
    for (int i=0;i<n;i++){
        ans = min(ans,dp[i][(1LL << n)-1]);
    }
    cout << fixed << setprecision(2) << ans << '\n';
}