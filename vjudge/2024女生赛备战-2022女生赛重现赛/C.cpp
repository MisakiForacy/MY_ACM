#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const double PI = acos(-1.0);
int main(){
    int T;
    // cin >> T;
    T = 1;
    
    while (T--){
        double n,r,th;
        cin >> n >> r >> th;
        th = min(2*PI-th,th);
        vector<int> a(n);
        double ans = th*r;
        for (int i=0;i<n;i++){
            cin >> a[i];
            ans = min(ans,2*(r-a[i])+th*a[i]);
        }
        cout << fixed << setprecision(6) << ans << '\n';
    }
}