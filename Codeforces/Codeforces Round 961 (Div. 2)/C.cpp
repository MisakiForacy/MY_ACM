#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, ok = 1;
        cin >> n;
        vector<ll>ar(n+1,1);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
            if (ar[i] == 1 && ar[i-1] > ar[i]) ok = 0;
        }
        if (ok){
            ll cnt = 0, now = 1, sum = 0;
            for (int i=1;i<n;i++){
                now = ar[i];
                while (now < ar[i+1] && cnt){
                    now *= now;
                    cnt --;
                }
                ll suf = ar[i+1];
                while (now > suf){
                    suf *= suf;
                    cnt ++;
                }
                sum += cnt;
            }
            cout << sum << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}