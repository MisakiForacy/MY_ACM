#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,b,c;
        cin >> n >> b >> c;
        if (b == 0){
            if (c >= n){
                cout << n << '\n';
            } else if (c >= n - 2){
                cout << n - 1 << '\n';
            } else{
                cout << -1 << '\n';
            }
        } else{
            cout << n - max(1LL,(n-1+b-c)/b+1) + 1 << '\n';
        }
    }
}