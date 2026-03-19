#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll T,n,mi;
    cin >> T;
    while (T --){
        mi = inf;
        cin >> n;
        vector<ll>ar(n);
        cin >> ar[0];
        for (int i=1;i<n;i++){
            cin >> ar[i];
            if (max(ar[i-1],ar[i])<mi){
                mi = max(ar[i-1],ar[i]);
            }
        }
        cout << mi - 1 << '\n';
    }
}