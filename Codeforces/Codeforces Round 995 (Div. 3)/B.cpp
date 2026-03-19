#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int T;
    cin >> T;
    while (T--){
        LL n,a,b,c;
        cin >> n >> a >> b >> c;
        LL res = n % (a+b+c);
        LL d = n / (a+b+c) * 3;
        if (res > a+b ){
            d += 3;
        } else if (res > a){
            d += 2;
        } else if (res > 0){
            d += 1;
        }
        cout << d << '\n';
    }
}