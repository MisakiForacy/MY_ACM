#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3f3f3f3f
#define N (i64)(1e6+10)
#define mod (i64)(1e9+7)
#define PI 3.1415926
using namespace std;
typedef long long i64;
typedef double llf;
bool flg;
i64 cnt,tot,ans,res;
i64 d,i,j,k,s,t,a;
i64 n,l,r;
llf f;
string str;
vector<i64>arr;
vector<vector<i64>>matrix;
void solve();
i64 count(string s);
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    str = "aaa";
    // cout << count(str.substr(0,1)) << endl;
    while(t--){
        solve();
    }
    return 0;
}
void solve(){
    cin >> n >> l >> r;
    cin >> str;
    for(i=n/l;i>-1;i--){
        if(count(str.substr(0,i))>=l){
            cout << i << endl;
            break;
        }
    }
}
i64 count(string s){
    i64 len = s.length();
    cnt = 0;
    for(j=0;j<=str.length()-len;j++){
        if(s == str.substr(j,len))cnt++;
    }
    return cnt;
}