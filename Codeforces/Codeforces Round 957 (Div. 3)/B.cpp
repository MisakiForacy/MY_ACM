#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,k,ans = 0;
        cin >> n >> k;
        vector<ll>ar(k);
        for (int i=0;i<k;i++){
            cin >> ar[i];
        }
        sort(ar.begin(),ar.end());
        for (int i=0;i<k-1;i++){
            ans += ar[i]*2 - 1;
        }
        cout << ans << '\n';
    }
}