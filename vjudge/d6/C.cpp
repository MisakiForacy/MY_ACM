#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if (a > b + c){
        if (a == 1) cout << "YES\n" << 0 << '\n';
        else cout << "YES\n" << 2*(b+c)+1 << '\n';
    } else cout << "NO\n";
}