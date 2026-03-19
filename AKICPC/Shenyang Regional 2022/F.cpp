#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6+10;
LL c[N];
void init(){
    LL x = 0;
    for (int i=1;i<N;i++){
        c[i] = c[i-1] + (++x);
    }
}
void solve(){
    LL n,m;
    cin >> n >> m;
    int ok = 0;
    if (((n+1)/2)%2==0) ok = 1;
    if (((m+1)/2)%2==0) ok = 1;
    if (!ok){
        cout << "No\n";
        return;
    } else{
        cout << "Yes\n";
        if (((n+1)/2)%2==0){
            vector<int> a(n+2,0);
            LL x = n*(n+1)/4;
            LL cnt = 1;
            int f = 0;
            while (x){
                LL len = lower_bound(c+1,c+N,x-n+cnt)-c;
                x -= c[len];
                for (int i=0;i<len;i++){
                    a[cnt++] = f;
                }
                f ^= 1;
            }
            for (int i=1;i<=n;i++){
                for (int j=1;j<=m;j++){
                    cout << a[i] << " \n"[j==m];
                }
            }
        } else{
            vector<int> a(m+2,0);
            LL x = m*(m+1)/4;
            LL cnt = 1;
            int f = 0;
            while (x){
                LL len = lower_bound(c+1,c+N,x-m+cnt)-c;
                x -= c[len];
                for (int i=0;i<len;i++){
                    a[cnt++] = f;
                }
                f ^= 1;
            }
            for (int i=1;i<=n;i++){
                for (int j=1;j<=m;j++){
                    cout << a[j] << " \n"[j==m];
                }
            }
        }
    }
}
int main(){
    init();
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}