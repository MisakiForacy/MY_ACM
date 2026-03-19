#include <bits/stdc++.h>
using namespace std;
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
        if (n==2 && abs(a[0]-a[1])!=1){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
}