#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main(){
    int n;
    cin >> n;
    vector<ll>ar(n+1,0);
    vector<ll>prefix(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        prefix[i] = ar[i] + prefix[i-1];
    }
    ll ma,mi,hi;
    ma = -inf;
    mi = 0;
    for (int i=1;i<=n;i++){
        if (prefix[i]>=ma){
            ma = prefix[i];
            hi = i;
        }
    }
    for (int i=1;i<hi;i++){
        if (prefix[i]<=mi){
            mi = prefix[i];
        }
    }
    cout << ma-mi << '\n';
}