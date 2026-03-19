#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 t,n,i,k,cnt;
vector<i64>arr;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
void solve(){
    cin >> n;
    cnt = 0;
    arr.resize(n);
    for(i=0;i<n;i++)cin >> arr[i];
    sort(arr.begin(),arr.end());
    k = (n + 1) / 2 - 1;
    for(i = n - 1; i >= k; i --){
        if(arr[i] == arr[k])cnt ++;
    }
    cout << cnt << '\n';
}   