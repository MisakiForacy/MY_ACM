#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
string n1,n2;
i64 t,i,j,len;
bool flg;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    flg = true;
    cin >> n1 >> n2;
    len = n1.length();
    for(i=0;i<len;i++){
        if(flg && n1[i] < n2[i]){
            swap(n1[i],n2[i]);
            flg = false;
        }
        else if(flg && n1[i] > n2[i]){
            flg = false;
        }
        else if(!flg && n1[i] > n2[i]){
            swap(n1[i],n2[i]);
        }
    }
    cout << n1 << '\n';
    cout << n2 << '\n';
}