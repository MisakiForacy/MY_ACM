#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,t,ans,base;
        cin >> n;
        t = n, ans = n,base = 1;
        while (t){
            if (t&1){
                ans -= base;
                break;
            }
            base <<= 1;
            t >>= 1;
        }
        cout << (ans?ans:-1) << '\n';
    }
}