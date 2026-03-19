#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,n;
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
    vector<int>a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a.begin(),a.end());
    n = unique(a.begin(),a.end()) - a.begin();
    if(n == 1){
        cout << "Yes" << endl;
        return;
    }
    if(n != 3){
        cout << "No" << endl;
        return;
    }
    else{
        if(__gcd(a[2],a[1]) == a[0]){
            cout << "Yes" << endl;
            return;
        }
        else{
            cout << "No" << endl;
            return;
        }
    }
}