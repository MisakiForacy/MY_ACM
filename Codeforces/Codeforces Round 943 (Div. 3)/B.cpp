#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
string s1,s2;
bool flg;
i64 t,a,b,i,j,k,cnt;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
void solve(){
    flg = true;
    cin >> a >> b;
    cin >> s1 >> s2;
    k = 0, cnt = 0;
    for(i=0;i<a;i++){
        while(k<b){
            if(s1[i] == s2[k]){
                cnt++;
                k++;
                break;
            }
            k++;
        }
    }
    cout << cnt << endl;
}