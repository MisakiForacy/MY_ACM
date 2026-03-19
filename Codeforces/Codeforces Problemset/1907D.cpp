#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5+10;
int L[N],R[N];
bool check(int k,int n){
    LL ll = 0, rr = 0;
    int ok = 1;
    for (int i=1;i<=n;i++){
        ll = max(ll-k,(LL)L[i]);
        rr = min(rr+k,(LL)R[i]);
        if (ll > rr){
            ok = 0;
        }
    }
    return ok;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        L[0] = R[0] = 0;
        LL lo = 0, hi = LLONG_MIN;
        for (int i=1;i<=n;i++){
            cin >> L[i] >> R[i];
            hi = max({hi,(LL)abs(L[i]-R[i-1]),(LL)abs(R[i]-L[i-1])});
        }
        while (lo <= hi){
            LL mid = lo + hi >> 1;
            if (check(mid,n)) hi = mid - 1;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
}