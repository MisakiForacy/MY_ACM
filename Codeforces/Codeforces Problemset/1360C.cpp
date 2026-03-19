#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll T,n,even,odd,cnt,a[105];
    cin >> T;
    while (T --){
        memset(a,-1,sizeof(a));
        cin >> n;
        odd = even = cnt = 0;
        vector<ll>ar(n);
        for (int i=0;i<n;i++){
            cin >> ar[i];
        }
        sort(ar.begin(),ar.end());
        for (int i=0;i<n;i++){
            if (a[i]&&i+1!=n&&ar[i+1]-ar[i]==1){
                a[i] = 0, a[i+1] = 0;
                cnt ++;
                continue;
            } else{
                if (a[i]&&ar[i]%2){
                    a[i] = 0;
                    odd ++;
                } else if (a[i]){
                    a[i] = 0;
                    even ++;
                }
            }
        }
        if ((even%2) != (odd%2)){
            cout << "NO\n";
        } else if (even%2){
            if (cnt){
                cout << "YES\n";
            } else{
                cout << "NO\n";
            }
        } else{
            cout << "YES\n";
        }
    }
}