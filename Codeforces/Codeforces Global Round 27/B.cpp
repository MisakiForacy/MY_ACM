#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n==1 || n==3){
            cout << -1 << '\n';
        } else{
            if (n==2){
                cout << "66\n";
            } else{
                for (int i=0;i<n-4;i++){
                    cout << '3';
                }
                if (n&1){
                    cout << "6366\n";
                } else{
                    cout << "3366\n";
                }
            }
        }
    }
}