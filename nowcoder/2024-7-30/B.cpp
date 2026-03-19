#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        int ok;
        ll n,m,a,b;
        cin >> n >> m >> a >> b;
        if ((n*m)%2){
            ok = 0;
        } else{
            if ((a)&&(b)){
                ok = 1;
            } else if ((!a)&&(b)){
                if (n==2||m==2){
                    ok = 1;
                } else{
                    ok = 0;
                }
            } else if ((a)&&(!b)){
                if ((n==1&&m%2==0)||(m==1&&n%2==0)){
                    ok = 1;
                } else{
                    ok = 0;
                }
            } else if ((!a)&&(!b)){
                if ((m==1&&n==2)||(m==2&&n==1)){
                    ok = 1;
                } else{
                    ok = 0;
                }
            }
        }
        cout << (ok?"Yes\n":"No\n");
    }
}