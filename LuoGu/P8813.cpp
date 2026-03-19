#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 a,b,res;
int main(){
    res = 1;
    cin >> a >> b;
    for (int i=0;i<b;i++){
        res *= a;
        if(res > 1e9){
            res = -1;
            break;
        }
    }
    cout << res << endl;
    return 0;
}