#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int a,b,c;
        cin >> a >> b >> c;
        if ((a&1)&&(b&1)&&(c&1)){
            cout << "NO\n";
        } else if ((!(a&1))&&(!(b&1))&&(!(c&1))){
            if (((a/2)&1)&&((b/2)&1)&&((c/2)&1)){
                cout << "NO\n";
            }
        } else{
            cout << "YES\n";
        }
    }
}