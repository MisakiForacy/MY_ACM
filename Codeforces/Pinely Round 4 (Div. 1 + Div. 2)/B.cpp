#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,ok = 1;
        cin >> n;
        vector<int>b(n),a(n);
        for (int i=1;i<n;i++){
            cin >> b[i];
        }
        a[0] = b[1];
        for (int i=1;i<n;i++){
            a[i] = b[i];
            if ((a[i]&a[i-1])!=b[i]){
                a[i-1] |= a[i];
            }
        }
        for (int i=1;i<n;i++){
            if ((a[i]&a[i-1])!=b[i]){
                ok = 0;
            }
        }
        if (ok){
            for (int i=0;i<n;i++){
                cout << a[i] << " \n"[i==n-1];
            }
        } else{
            cout << -1 << '\n';
        }
    }
}