#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double x){
    double res = a*x*x*x + b*x*x + c*x + d;
    return fabs(res)<=0.01;
}
int main(){
    cin >> a >> b >> c >> d;
    set<double> ans;
    for (double i=-100.00;i<=100.00;i+=0.01){
        if (f(i)){
            ans.insert(i);
        }
    }
    for (auto x:ans){
        cout << fixed << setprecision(2) << x << ' ';
    }
}