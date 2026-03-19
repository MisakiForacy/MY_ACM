#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,k,ok=0;
        cin >> n >> k;
        if (n==k){
            ok = 1;
        } else if (k==1 && n&1){
            ok = 1;
        }
        cout << (ok?'A':'B');
    }
}