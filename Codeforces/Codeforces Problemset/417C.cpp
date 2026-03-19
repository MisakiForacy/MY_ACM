#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,k;
    cin >> n >> k;
    if (1+2*k>n){
        cout << -1 << '\n';
    } else{
        cout << n * k << '\n';
        for (int i=1;i<=n;i++){
            for (int j=1;j<=k;j++){
                cout << i << ' ' << (i+j==n?n:(i+j)%n) << '\n';
            }
        }
    }
}