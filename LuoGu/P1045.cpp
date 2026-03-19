#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double mlog(double a,double b){ // a 为底数
    return __builtin_log(b)/__builtin_log(a);
}
int main(){
    ll p;
    cin >> p;
    cout << ceil(p*mlog(10,2)) << '\n';
}