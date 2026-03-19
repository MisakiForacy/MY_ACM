#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll a,b,x,y;
        cin >> a >> b >> x >> y;
        if (y <= x){
            cout << (a+b) * y << '\n';
        } else{
            cout << a * x + b * y << '\n';
        }
    }
}