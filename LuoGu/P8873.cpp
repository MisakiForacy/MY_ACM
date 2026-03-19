#include <bits/stdc++.h>
using namespace std;
using LL = long long;
bool check(LL x,LL k){
    if ((x*2+1) >= 1.0*k/(x+1)) return 1;
    return 0;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        LL k;
        cin >> k;
        LL lo = 0, hi = k;
        while (lo <= hi){
            LL mid = lo + hi >> 1;
            if (check(mid,k)) hi = mid - 1;
            else lo = mid + 1;
        }
        k -= lo*((lo-1)*2+1);
        if (k >= 3*lo + 1){
            cout << k-lo*4-1 << '\n';
        } else if (k >= 2*lo + 1){
            cout << 2*lo+1 - k << '\n';
        } else if (k > lo){
            cout << 2*lo+1 - k << '\n';
        } else{
            cout << k - 1 << '\n';
        }
    }
}