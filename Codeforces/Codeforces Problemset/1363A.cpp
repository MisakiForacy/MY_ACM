#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,x,o,e,f=0;
        cin >> n >> x;
        vector<ll>ar(n);
        o = e = 0;
        for (int i=0;i<n;i++){
            cin >> ar[i];
            if (ar[i]&1){
                o ++;
            } else{
                e ++;
            }
        }
        for (int i=1;i<=x;i+=2){
            if (o>=i&&e>=(x-i)){
                f = 1;
            }
        }
        cout << (f?"Yes\n":"No\n");
    }
}