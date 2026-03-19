#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T,n,ma,sum,cnt;
    cin >> T;
    while (T --){
        cin >> n;
        sum = cnt = 0;
        vector<ll>ar(n);
        cin >> ar[0];
        ma = ar[0];
        sum = ar[0];
        if (ar[0]==0){
            cnt ++;
        }
        for (int i=1;i<n;i++){
            cin >> ar[i];
            sum += ar[i];
            if (ar[i]>ma){
                ma = ar[i];
            }
            if (sum-ma==ma){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}