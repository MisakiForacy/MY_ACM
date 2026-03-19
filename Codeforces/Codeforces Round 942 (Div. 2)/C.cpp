#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(1e6+10)
#define mod (i64)(1e9+7)
#define INF 0x3f3f3f3f
#define PI 3.1415926
using namespace std;
typedef long long i64;
typedef double llf;
bool flag;
i64 maxn = -INF, minn = INF;
i64 n,m,k,t,i,j,cnt;
llf f,l;
string s, str;
char c;
vector<i64>arr;
vector<vector<i64>>matrix;
static inline void solve();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
static inline void solve(){
    cin >> n >> k;
    cnt = 0;
    arr.resize(n);
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    
}