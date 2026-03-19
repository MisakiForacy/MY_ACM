#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        if (n&1){
            cout << "Kosuke\n";
        } else{
            cout << "Sakurako\n";
        }
    }
}