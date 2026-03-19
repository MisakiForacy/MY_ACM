#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD = 1e9+7;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,k;
        cin >> n >> k;
        if (k == 1){
            cout << n % MOD << '\n';
        } else{
            int n1,n2,n3,t;
            n1 = n2 = 1;
            t = 2;
            do{
                t ++;
                n3 = (n1 + n2) % k;
                n1 = n2, n2 = n3;
                if (!n3){
                    cout << n % MOD * t % MOD << '\n';
                    break;
                }
            } while (1);
        }
    }
}