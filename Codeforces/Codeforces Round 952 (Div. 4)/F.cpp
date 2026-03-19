#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
#define N (ll)(2e5+10)
using namespace std;
typedef long long ll;
ll a[N],c[N];
bool check(ll mid,ll h,ll n){
    ll cnt=0;
    mid --;
    for (int i=0;i<n;i++){
        cnt += (mid/c[i]+!!(mid%c[i]))*a[i];
        if (cnt >= h){
            return 1;
        }
    }
    return 0;
}
int main(){
    ll T,h,n,r,l,mid;
    cin >> T;
    while (T --){
        l = 1, r = 4e10;
        cin >> h >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> c[i];
        while (l<=r){
            mid = (l+r)/2;
            if (check(mid,h,n)){
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        cout << l-1 << '\n';
    }
}