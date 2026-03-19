#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n,k,t,r,c;
        cin >> n;
        k = 0;
        while (!(k*k<n&&(k+1)*(k+1)>=n)){
            k ++;
        }
        t = k*(k+1)+1;
        if (n<=t){
            c = k+1;
            r = k+1-(t-n);
        } else{
            r = k+1;
            c = k+1-(n-t);
        }
        cout << r << ' ' << c << '\n';
    }
    return 0;
}