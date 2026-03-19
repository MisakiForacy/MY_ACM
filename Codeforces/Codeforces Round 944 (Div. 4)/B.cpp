#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(2e5+10)
using namespace std;
typedef long long i64;
bool flg;
i64 t,n,m,k,cnt,tot,res;
string s,r;
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
    flg = false;
    cin >> s;
    for(int i = 1; i < s.length(); i ++){
        if(s[i] != s[0]){
            flg = true;
            swap(s[i],s[0]);
            break;
        }
    }
    if(flg)cout << "YES\n" << s << endl;
    else cout << "NO\n";
}