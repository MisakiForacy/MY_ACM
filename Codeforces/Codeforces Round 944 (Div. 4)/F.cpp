#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
bool flg;
i64 t,r,cnt;
void solve();
int main(){
    scanf("%lld",&t);
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    scanf("%lld",&r);
    cnt = 0;
    for(int i=r;i>0;i--){
        for(i64 j=(i64)sqrt(1ll*r*r-1ll*i*i);j<=(i64)sqrt(1ll*(r+1)*(r+1)-1ll*i*i);j++){
            if((i64)sqrt(1ll*i*i+1ll*j*j)==r)cnt ++;
        }
    }
    printf("%d\n",cnt*4);
}