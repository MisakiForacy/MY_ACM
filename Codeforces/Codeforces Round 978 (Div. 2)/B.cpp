#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end(),[&](int x,int y){
            return x > y;
        });
        
    }
}