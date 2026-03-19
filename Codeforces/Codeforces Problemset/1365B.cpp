#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,ok = 1;
        cin >> n;
        vector<int>a(n);
        vector<int>b(n);
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> b[i];
        for (int i=1;i<n;i++){
            if (a[i]<a[i-1]) ok = 0;
        }
        if (!ok){
            int f0,f1;
            f0 = f1 = 0;
            for (int i=0;i<n;i++){
                if (b[i]) f1 = 1;
                else f0 = 1;
            }
            ok = f0 & f1;
        }
        cout << (ok?"YES\n":"NO\n");
    }
}