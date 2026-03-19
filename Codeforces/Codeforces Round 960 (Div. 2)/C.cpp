#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int nn[N],nnn[N];
int main(){
    int T,t=0;
    cin >> T;
    while (T--){
        t ++;
        ll n,mx = 0,sum = 0;
        cin >> n;
        vector<ll>ar(n),b(n+1,0),c(n);
        memset(nn,0,sizeof(nn));
        memset(nnn,0,sizeof(nnn));
        for (int i=0;i<2;i++){
            mx = 0;
            memset(nn,0,sizeof(nn));
            for (int j=0;j<n;j++){
                if (i==0) cin >> ar[j];
                sum += ar[j];
                nn[ar[j]] ++;
                if (nn[ar[j]]>=2){
                    mx = max(mx,ar[j]);
                }
                b[j] = mx;
                if (i==1) nnn[b[j]]++;
                ar[j] = b[j];
            }
        }
        for (int i=0;i<n;i++){
            if (nnn[b[i]]>1){
                b[i] *= (n-i);
            }
            sum += b[i];
        }
        cout << sum << '\n';
    }
}