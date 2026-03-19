#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        if (n==1){
            cout << 1 << '\n';
            cout << 1 << '\n';
        } else{
            if (k == n || k == 1){
                cout << -1 << '\n';
            } else if (!(k&1)){
                cout << 3 << '\n';
                cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
            } else{
                cout << 3 << '\n';
                cout << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
            }
        }
    }
}