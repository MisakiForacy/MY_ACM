#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin >> n;
    vector<ll>ar(n+1,0),prefix(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        prefix[i] = ar[i]+prefix[i-1];
    }
    cin >> m;
    for (int i=0;i<m;i++){
        ll x,lo,hi,mid;
        lo = 1, hi = n+1;
        cin >> x;
        while (lo <= hi){
            mid = (lo+hi)>>1;
            if (x>prefix[mid]){
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        cout << lo << '\n';
    }
}