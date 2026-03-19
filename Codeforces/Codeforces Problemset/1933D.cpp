#include <bits/stdc++.h>
using namespace std;
int main(){
    int T,n;
    cin >> T;
    while (T--){
        cin >> n;
        vector<int>a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        if (a[0]!=a[1]){
            cout << "YES\n";
        } else{
            int ok = 1;
            for (int i=1;i<n;i++){
                if (a[i]%a[0]!=0){
                    cout << "YES\n";
                    ok = 0;
                    break;
                }
            }
            if (ok){
                cout << "NO\n";
            }
        }
    }
}