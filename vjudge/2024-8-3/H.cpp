#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int>a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        int ok = 1;
        for (int i=0;i<n-2;i++){
            a[i+2] -= a[i];
            a[i+1] -= a[i] * 2;
            a[i] = 0;
            if (a[i+1]<0||a[i+2]<0){
                ok = 0;
                break;
            }
        }
        if (a[n-2]||a[n-1]) ok = 0;
        cout << (ok?"YES\n":"NO\n");
    }
}