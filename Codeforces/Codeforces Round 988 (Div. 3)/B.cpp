#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
using namespace std;
using LL = long long;
void solve(){
    int k,x;
    cin >> k;
    map<int,int> mp;
    vector<int> a(k);
    for (int i=0;i<k;i++){
        cin >> a[i];
        mp[a[i]] ++;
    }
    for (int i=0;i<k;i++){
        if ((k-2)%a[i] == 0){
            if ((k-2)/a[i] == a[i]){
                if (mp[a[i]] > 1){
                    cout << a[i] << ' ' << a[i] << '\n';
                    return;
                }
            } else{
                if (mp[(k-2)/a[i]]){
                    cout << a[i] << ' ' << (k-2)/a[i] << '\n';
                    return;
                }
            }
        }
    }
    return;
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}