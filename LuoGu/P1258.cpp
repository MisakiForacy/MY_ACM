#include <bits/stdc++.h>
using namespace std;
int main(){
    double s,a,b;
    cin >> s >> a >> b;
    double x = (a+b)*s/(b+3*a);
    cout << fixed << setprecision(6) << x/b+(s-x)/a << '\n';
}