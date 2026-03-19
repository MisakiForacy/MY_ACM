#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(2*n);
        int n0 = 0,n1 = 0;
        for (int i=0;i<2*n;i++){
            cin >> a[i];
            if (a[i] == 0){
                n0 ++;
            } else{
                n1 ++;
            }
        }
        cout << n0%2 << ' ' << min(n0,n1) << '\n';
    }
}