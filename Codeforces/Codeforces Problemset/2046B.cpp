#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<array<int,2>> a(n);
        vector<int> b(n),c;
        for (int i=0;i<n;i++){
            cin >> a[i][0];
            a[i][1] = i;
            b[i] = a[i][0];
        }
        sort(a.begin(),a.end(),[&](auto x,auto y){
            if (x[0] != y[0]) return x[0] < y[0];
            return x[1] > y[1];
        });
        
    }
}