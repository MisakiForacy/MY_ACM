#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,q;
        cin >> n >> m >> q;
        vector<int> a(n);
        vector<int> b(m);
        map<int,int> mp;
        for (int i=0;i<n;i++) cin >> a[i], mp[a[i]] = i;
        for (int i=0;i<m;i++) cin >> b[i];
        int k = 0;
        int ok = a[0] == b[0];
        for (int i=1;i<m;i++){
            if (mp[b[i]]>k){
                k ++;
                if (a[k]!=b[i]){
                    ok = 0;
                    break;
                }
            }
            if (k==n){
                break;
            }
        }
        cout << (ok?"YA\n":"TIDAK\n");
    }
}