#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,lo,hi,k=3,f=0;
        cin >> n;
        vector<ll>ar(n+1),ans(n+1);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        sort(ar.begin()+1,ar.end());
        lo = 2;hi = n-1;
        ans[1] = ar[n], ans[2] = ar[1];
        while (k<=n){
            if (!f){
                ans[k] = ar[hi];
                hi --;
            } else{
                ans[k] = ar[lo];
                lo ++;
            }
            k ++;
            f = !f;
        }
        for (int i=n;i>=1;i--){
            cout << ans[i] << " \n"[i==1];
        }
    }
}