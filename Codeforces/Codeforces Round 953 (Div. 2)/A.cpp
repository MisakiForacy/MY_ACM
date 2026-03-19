#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    ll n,ma,x;
    cin >> T;
    while (T--){
        ma = 0;
        cin >> n;
        for (int i=0;i<n-1;i++){
            cin >> x;
            ma = max(ma,x);
        }
        cin >> x;
        cout << ma + x << '\n';
    }
}