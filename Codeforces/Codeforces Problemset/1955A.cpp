#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,a,b;
        cin >> n >> a >> b;
        if (a*2<b){
            cout << n * a << '\n';
        } else{
            if (n&1){
                cout << a + n/2*b << '\n';
            } else{
                cout << n/2*b << '\n';
            }
        }
    }
}