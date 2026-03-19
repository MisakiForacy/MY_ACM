#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    ll n,k;
    cin >> T;
    while (T--){
        cin >> n >> k;
        if (k&1||k>(n/2+n%2)*(n/2)*2){
            cout << "No\n";
        } else{
            cout << "Yes\n";
            vector<ll>ar(n+1);
            for (int i=1;i<=n;i++){
                ar[i] = i;
            }
            ll lo = 1, hi = n;
            while (k){
                if (k >= (hi-lo)*2){
                    k -= (hi-lo)*2;
                    swap(ar[lo],ar[hi]);
                    hi --;
                    lo ++;
                } else{
                    hi --;
                }
            }
            for (int i=1;i<=n;i++){
                cout << ar[i] << " \n"[i==n];
            }
        }
    }
}