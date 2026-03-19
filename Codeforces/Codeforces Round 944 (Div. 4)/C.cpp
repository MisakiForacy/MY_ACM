#include <bits/stdc++.h>
#define N (i64)(2e5+10)
using namespace std;
typedef long long i64;
bool flg;
i64 t,a,b,c,d,cnt,tot,res;
vector<i64>arr;
vector<vector<i64>>matrix;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> a >> b >> c >> d;
    if(a<c&&c<b&&!(a<d&&d<b)){
        cout<<"YES\n";
    }
    else if(b<c&&c<a&&!(b<d&&d<a)){
        cout<<"YES\n";
    }
    else if(b<d&&d<a&&!(b<c&&c<a)){
        cout<<"YES\n";
    }
    else if(a<d&&d<b&&!(a<c&&c<b)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}