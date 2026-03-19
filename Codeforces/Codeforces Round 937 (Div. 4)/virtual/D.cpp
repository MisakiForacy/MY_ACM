#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 t, n, s, k;
bool flg;
const i64 prime[] = {10,11,101,111,1001,1011,1101,10001,10011,10101,10111};
void solve();
int main(){
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> n;
    string num = to_string(n);
    flg = true, k = 0;
    for(int i = 0; i < num.length(); i ++){
        if(!(num[i] == '0' || num[i] == '1')){
            flg = false;
            break;
        }
    }
    if(flg){
        cout << "Yes\n"; 
    }
    else{
        while(k < 11 && n != 1){
            if(n % prime[k] == 0){
                n /= prime[k];
            }
            else k ++;
        }
        if(k == 11)cout << "No\n";
        else cout << "Yes\n";
    }
}