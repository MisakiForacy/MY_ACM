#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int main(){
    i64 n1,m1,n2,m2,gcd;
    char c;
    cin >> n1 >> c >> m1;
    cin >> n2 >> c >> m2;
    gcd = __gcd(n1*n2,m1*m2);
    cout << (m1*m2)/gcd << " " << (n1*n2)/gcd << endl;
    return 0;
}