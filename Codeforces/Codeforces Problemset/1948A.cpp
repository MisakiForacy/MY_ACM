#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n&1){
            cout << "NO\n";
        } else{
            cout << "YES\n";
            for (int i=0;i<n/2;i++){
                cout << char('A'+i) << char('A'+i);
            }
            cout << '\n';
        }
    }
}