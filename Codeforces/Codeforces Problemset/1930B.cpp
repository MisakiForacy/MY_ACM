#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n,0);
        int t = 1;
        for (int i=0;i<n;i+=2){
            a[i] = t;
            t ++;
        }
        for (int i=(a[n-1]?n-2:n-1);i>0;i-=2){
            a[i] = t;
            t ++;
        }
        for (int i=0;i<n;i++){
            cout << a[i] << " \n"[i==n-1];
        }
    }
}