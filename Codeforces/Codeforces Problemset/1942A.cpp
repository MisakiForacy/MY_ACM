#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        if (n==k){
            for (int i=0;i<n;i++){
                cout << 1 << " \n"[i==n-1];
            }
        } else if (k==1){
            for (int i=1;i<=n;i++){
                cout << i << " \n"[i==n];
            }
        } else{
            cout << -1 << '\n';
        }
    }
}