#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<LL> a(n);
        LL sum = 0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            sum += a[i];
        }
        LL s1 = 0, s2 = 0;
        for (int i=0;i<n;i+=2){
            s1 += a[i];
        }
        for (int i=1;i<n;i+=2){
            s2 += a[i];
        }
        int ok = 1;
        if (sum % n != 0) ok = 0;
        if (s1 / (n/2+n%2) != s2 / (n/2)) ok = 0;
        cout << (ok ? "Yes\n" : "No\n");
    }
}