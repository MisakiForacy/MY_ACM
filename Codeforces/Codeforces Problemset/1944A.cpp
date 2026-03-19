#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        if (k >= n-1){
            cout << 1 << '\n';
        } else{
            cout << n << '\n';
        }
    }
}