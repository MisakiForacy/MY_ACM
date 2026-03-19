#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
            b[i] = a[i];
        }
        int ok = 1;
        sort(b.begin(),b.end());
        for (int i=0;i<n;i++){
            if (abs(a[i]-b[i])>1){
                ok = 0;
            }
        }
        cout << (ok ? "YES\n":"NO\n");
    }
}