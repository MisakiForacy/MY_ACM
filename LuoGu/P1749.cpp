#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
i64 t,n,k,i,j,res;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        res = 0;
        cin >> n >> k;
        if(n<(1+k)*k/2)cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}