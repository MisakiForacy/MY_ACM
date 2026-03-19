#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int>a(n),b;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    b.push_back(a.back());
    for (int i=n-2;i>=0;i--){
        if (a[i] <= b.back()){
            b.push_back(a[i]);
        } else{
            if (a[i] >= 10){
                b.push_back(a[i]%10);
                b.push_back(a[i]/10);
            } else{
                b.push_back(a[i]);
            }
        }
    }
    cout << (is_sorted(b.rbegin(),b.rend())?"YES\n":"NO\n");
}
int main(){
    int T;
    cin >> T;
    while (T--){
        solve();
    }
}