#include <bits/stdc++.h>
#define endl '\n'
#define mod ll(1e9 + 7)
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n,x,res;
    cin >> n;
    while(n--){
        cin >> x;
        res = x*2%mod;
        cout << res << endl;
    }
}