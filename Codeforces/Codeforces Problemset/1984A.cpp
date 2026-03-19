#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    ll n,idx;
    cin >> T;
    while (T--){
        cin >> n;
        vector<ll>ar(n);
        idx = n-1;
        for (int i=0;i<n;i++){
            cin >> ar[i];
            if (i>=1 && ar[i]==ar[i-1]){
                idx = i;
            }
        }
        if (unique(ar.begin(),ar.end())-ar.begin()==1){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=0;i<n;i++){
                cout << "RB"[i==idx];
            }
            cout << '\n';
        }
    }
}