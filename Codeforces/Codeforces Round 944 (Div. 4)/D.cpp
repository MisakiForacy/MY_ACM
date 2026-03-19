#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(2e5+10)
using namespace std;
typedef long long i64;
bool f1,f2;
i64 t,n,m,k,cnt,tot,res;
string s;
vector<i64>arr;
vector<vector<i64>>matrix;
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
    cin >> s;
    cnt = 1;
    if(s.length() == 1)cnt = 1;
    else{
        for(int i = 1; i < s.length(); i ++){
            if(s[i] != s[i-1]){
                cnt ++;
            }
        }
        for(int i = 1; i < s.length(); i ++){
            if(s[i] == '1' && s[i-1] == '0'){
                cnt --;
                break;
            }
        }
    }
    cout << cnt << endl;
}