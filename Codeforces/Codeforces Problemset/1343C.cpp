#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    while (T--){
        ll n,s,f,m;
        cin >> n;
        vector<ll>ar(n);
        cin >> ar[0];
        f = (ar[0]>0);
        s = m = ar[0];
        for (int i=1;i<n;i++){
            cin >> ar[i];
            if ((ar[i]>0)^f){
                f = !f;
                m = ar[i];
                s += m;
            } else if (ar[i]>m){
                s -= m;
                m = ar[i];
                s += m;
            }
        }
        cout << s << '\n';
    }
}