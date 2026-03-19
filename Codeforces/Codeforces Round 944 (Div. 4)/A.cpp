#include <bits/stdc++.h>
#define N (i64)(2e5+10)
using namespace std;
typedef long long i64;
bool flg;
i64 t,n,m,k,cnt,tot,res;
vector<i64>arr;
vector<vector<i64>>matrix;
void solve();
int main(){
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> n >> m;
    cout << min(m,n) << " " << max(m,n) << endl;
}