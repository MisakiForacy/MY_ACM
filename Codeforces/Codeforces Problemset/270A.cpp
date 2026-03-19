#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,a;
    cin >> T;
    while (T--){
        cin >> a;
        if (360%(180-a)){
            cout << "NO\n";
        } else{
            cout << "YES\n";
        }
    }
}