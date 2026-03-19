#include <bits/stdc++.h>
using namespace std;
using LL = long long;
double n,a,va,b,vb;
bool check(double t){
    double a1 = (va*t - a);
    double a2 = (va*t - a) / 2 + a;
    double b1 = (vb*t - (n-b));
    double b2 = (vb*t - (n-b)) / 2 + (n-b);
    if (a1 < 0 || a2 < 0 || b1 < 0 || b2 < 0){
        return 0;
    }
    if (a1+b1 >= n || a1+b2 >= n || a2+b1 >= n || a2+b2 >= n){
        return 1;
    }
    return 0;
}
int main(){
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> a >> va >> b >> vb;
        if (a > b){
            swap(a,b);
            swap(va,vb);
        }
        double case1 = min({(2*n-a)/va,(n+a)/va,(n+b)/vb,(2*n-b)/vb,max((n-a)/va,b/vb)});
        double lo = 0, hi = case1;
        while (lo <= hi){
            double mid = (lo + hi) / 2;
            if (check(mid)){
                hi = mid - 0.00000001;
            } else{
                lo = mid + 0.00000001;
            }
        }
        cout << lo << '\n';
    }
}