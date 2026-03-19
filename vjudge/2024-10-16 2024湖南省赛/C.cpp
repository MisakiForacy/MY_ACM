#include <bits/stdc++.h>
using namespace std;
using LL = long long;
double mlog(double a,double b){
    return __builtin_log(b) / __builtin_log(a);
}
int main(){
    int n,x;
    cin >> n;
    double tot = 0;
    for (int i=0;i<n;i++){
        cin >> x;
        tot += mlog(2,x);
    }
    double m = mlog(2,2024);
    double cnt = 0;
    while (m * cnt < tot){
        cnt ++;
    }
    cout << cnt << '\n';
}