#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        int ok = 1;
        for (int i=1;i<n;i++){
            if (abs(a[i] - a[i-1]) != 5 && abs(a[i] - a[i-1]) != 7){
                ok = 0;
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }
}