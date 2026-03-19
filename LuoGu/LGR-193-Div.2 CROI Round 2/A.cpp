#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,k,x,ans = 0;
        cin >> n >> k;
        for (int i=0;i<k;i++){
            cin >> x;
            if (x==1){
                ans += pow(2,i);
            }
        }
        cout << ans + 1 << '\n';
    }
}