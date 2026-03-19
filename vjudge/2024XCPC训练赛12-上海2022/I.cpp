#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const double PI = acos(-1.0);
double n,m;
double dp[505][505];
double f(int x,int r){
    // if (x < 2*m/PI){
    //     return (2*PI*r*x)/m;
    // } else{
    //     return 4*r;
    // }
    dp[x][r] = min(dp[x][r-1]+2,x*PI*r/m);
    return 2 * dp[x][r];
}
double F(double r){ // 从一个点出发到同一个圆的其他交点的距离
    double res = 0;
    for (int i=1;i<m;i++){
        res += f(i,r);
    }
    return res + 2*r;
}
double g(double r){ // 在同一个圆上任意一个点出发到其他交点的距离总和
    return F(r)*m;
}
double h(double r){ // 
    double res = 0;
    for (int i=1;i<=n-r;i++){
        res += 2*m*(F(r)+2*m*i);
    }
    return res;
}
double t(double r){
    return 2*m*r;
}
int main(){
    cin >> n >> m;
    double ans = 0;
    for (int i=1;i<=n;i++){
        ans += g(i) + h(i);
        if (m > 1){
            ans += t(i);
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
}