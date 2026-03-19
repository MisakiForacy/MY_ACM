#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int a,b;
        cin >> a >> b;
        if (a >= b){
            cout << a << '\n';
        } else{
            cout << max(0,a-(b-a)) << '\n';
        }
    }
}