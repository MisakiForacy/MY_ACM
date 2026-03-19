#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,a,b;
        vector<ll> arr(n);
        for (int i=0;i<n;i++) cin >> arr[i];
        sort(arr.begin(),arr.end());
        ll ans = arr.back() - arr.front();
        ll mx = arr.back();
        
    }
}