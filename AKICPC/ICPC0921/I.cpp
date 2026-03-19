#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(vector<int>ans,int n){
    ll res = 0;
    for (int i=0;i<32;i++){
        res += ans[i] * (1LL << i);
    }
    return (res == n);
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        vector<int> ans(32,-1);
        ans[31] = 1;
        ll nn = (n - 1) / 2;
        int pos = 0;
        while (nn){
            if (nn%2==1) ans[pos] = 1;
            nn /= 2;
            pos ++;
        }
        if (n%2==0){
            ans[0] = 0;
        }
        if (check(ans,n)){
            cout << "YES\n";
            for (int i=0;i<32;i++){
                cout << ans[i] << " \n"[(i+1)%8==0];
            }
        } else{
            cout << "NO\n";
        }
    }
}