#include <bits/stdc++.h>
using namespace std;
using LL = long long;
bool isprime(int n){
    for (int i=2;i<=sqrt(n);i++){
        if (n%i==0) return 0;
    }
    return 1;
}
int main(){
    LL n,nn;
    cin >> n;
    nn = n;
    map<int,int> mp;
    for (int i=2;i<=n;i++){
        if (isprime(i)){
            while (n%i==0){
                n /= i;
                mp[i] ++;
            }
        }
    }
    printf("%lld = ",nn);
    vector<pair<int,int>> ans;
    for (auto [k,v]:mp){
        ans.push_back({k,v});
    }
    if (ans[0].second > 1){
        cout << ans[0].first << '^' << ans[0].second;
    } else{
        cout << ans[0].first;
    }
    for (int i=1;i<ans.size();i++){
        cout << " * ";
        if (ans[i].second > 1){
            cout << ans[i].first << '^' << ans[i].second;
        } else{
            cout << ans[i].first;
        }
    }
}