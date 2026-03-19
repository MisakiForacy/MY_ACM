#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n&1){
            for (int i=n;i>=1;i-=2){
                cout << i << " ";
            }
            for (int i=2;i<n;i+=2){
                cout << i << " ";
            }
            cout << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}