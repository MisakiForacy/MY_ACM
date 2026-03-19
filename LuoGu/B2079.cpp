#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef double llf;
int main(){
    i64 n,i;
    llf res = 1,d;
    cin >> n;
    d = 1;
    for(i=1;i<=n;i++){
        d *= i;
        res += 1/d;
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}