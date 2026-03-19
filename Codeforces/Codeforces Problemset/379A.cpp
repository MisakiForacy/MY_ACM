#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,s;
    cin >> a >> b;
    s = 0;
    for (int i=1;i<=a;i++){
        s ++;
        if (s%b==0){
            a ++;
        }
    }
    cout << s << '\n';
}