#include <bits/stdc++.h>
typedef long long i64;
using namespace std;
i64 t,a,b,c;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(a<b && b<c)cout << "STAIR" << endl;
        else if(a<b && b>c)cout << "PEAK" << endl;
        else cout << "NONE" << endl;
    }
    return 0;
} 