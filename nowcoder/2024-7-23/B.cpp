#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,d,x,h;
    cin >> n >> d;
    cin >> h;
    for (int i=1;i<n;i++){
        cin >> x;
        h = __gcd(x,h);
    }
    d = d % h;
    cout << min(d,h-d) << '\n';
}