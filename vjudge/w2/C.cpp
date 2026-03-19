#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    if (n==1) cout << 0 << '\n';
    else{
        if (m<=1) cout << "No!\n";
        else{
            ll nn = n;
            ll cnt = 1;
            while (nn > 1){
                nn /= m;
                cnt ++;
            }
            if (nn == 1){
                cout << cnt << '\n';
            } else{
                ll mm = m;
                while (mm < n) mm *= m;
                cout << "No " << mm - n << '\n';
            }
        }
    }
}