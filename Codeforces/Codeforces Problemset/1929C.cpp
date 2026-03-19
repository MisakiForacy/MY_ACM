#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll k,x,a,init;
        cin >> k >> x >> a;
        init = a;
        ll bet = 1,tot = 1;
        a -= bet;
        int ok = 1;
        for (int i=1;i<x;i++){
            bet = ((tot+1)/(k-1)) + ((tot+1)%(k-1)?1:0);
            a -= bet;
            tot += bet;
            if (a < 0){
                ok = 0;
            }
        }
        if (!ok || a*k <= init){
            cout << "NO\n";
        } else{
            cout << "YES\n";
        }
    }
}