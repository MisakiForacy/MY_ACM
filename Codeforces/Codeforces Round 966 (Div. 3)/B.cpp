#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x;
        cin >> n;
        vector<int>a(n+2,0);
        int ok = 1;
        cin >> x;
        a[x] = 1;
        for (int i=1;i<n;i++){
            cin >> x;
            if (a[x-1]==0&&a[x+1]==0){
                ok = 0;
            }
            a[x] = 1;
        }
        cout << (ok?"YES\n":"NO\n");
    }
}