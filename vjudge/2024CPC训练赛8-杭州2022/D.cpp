#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    while (cin >> n){
        vector<double> a(n);
        long double tot = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            tot += a[i];
        }
        tot /= (n+1);
        // printf("%.2lf",tot*2);
        cout << fixed << setprecision(6) << tot * 2;
        for (int i=1;i<n;i++){
            // printf(" %.2lf",tot);
            cout << ' ' << tot;
        }
        cout << '\n';
    }
}