#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for (int i=1;i<=T;i++){
        cout << "Case #" << i << ": ";
        int r,b;
        cin >> r >> b;
        int a = r * (r-1) / 2;
        int c = (r+b) * (r+b-1) / 2;
        if (a == 0){
            cout << "0/1\n";
        } else if (a == c){
            cout << "1/1\n";
        } else{
            int gcd = __gcd(a,c);
            a = a / gcd;
            c = c / gcd;
            cout << a << '/' << c << '\n';
        }
    }
}