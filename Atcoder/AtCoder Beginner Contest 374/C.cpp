#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    LL tot = 0;
    vector<LL> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
        tot += a[i];
    }
    sort(all(a),[&](LL x,LL y){
        return x > y;
    });
    cout << tot << '\n';
    LL half = tot / 2 + tot%2;
    LL res = tot - half;
    for (int i=0;i<n;i++){
        if (half - a[i]>=0){
            half -= a[i];
            cout << a[i] << '\n';
        }
    }
    cout << half << '\n';
    cout << half + res << '\n';
}