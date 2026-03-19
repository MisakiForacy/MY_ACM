#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,k;
        cin >> n >> k;
        if (k==1){
            cout << n << '\n';
        } else{
            int cnt = 0;
            while (n>=k){
                cnt += n%k;
                n /= k;
            }
            cout << cnt+n << '\n';
        }
    }
}