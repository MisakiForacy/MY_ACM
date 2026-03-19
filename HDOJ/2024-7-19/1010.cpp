#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[20010];
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,q;
        cin >> n >> q;
        vector<ll>ar(n+1);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        int l,r;
        int ans = 0,num,mx = 0;
        for (int i=1;i<=q;i++){
            cin >> l >> r;
            memset(a,0,sizeof(a));
            for (int j=l;j<=r;j++){
                a[ar[j]]++;
                if (a[ar[j]]>mx){
                    mx = a[ar[j]];
                    num = ar[i];
                } else if (a[ar[j]]==mx){
                    if (ar[j]>num){
                        num = ar[j];
                    }
                }
                cout << ar[j] << ":" << a[ar[j]] << ":" << num << '\n';
            }
            ans ^= num*i;
        }
        cout << ans << '\n';
    }
}