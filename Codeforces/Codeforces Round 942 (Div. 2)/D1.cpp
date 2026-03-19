#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define N (i64)(2e6+10)
#define mod (i64)(1e9+7)
#define INF 0x3f3f3f3f
#define PI 3.1415926
using namespace std;
typedef long long i64;
typedef double llf;
bool flag;
i64 maxn = -INF, minn = INF;
i64 n,m,k,t,i,j,cnt;
string s, str;
char c;
vector<i64>arr;
vector<vector<i64>>matrix;
static inline void solve();
static inline i64 gcd(int a,int b);
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
    cnt = 0;
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j+=i){
            if((i+j)%(j*gcd(i,j))==0){
                cnt++;
            }
            else if(i<=j){
                break;
            }
        }
    }
    cout << cnt << endl;
}
static inline i64 gcd(int a,int b){
    return b?gcd(b,a%b):a;
}