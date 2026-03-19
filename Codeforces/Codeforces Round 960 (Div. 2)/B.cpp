#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x,y;
        cin >> n >> x >> y;
        vector<int>ar(n+1,1);
        for (int i=y-1;i>=1;i-=2){
            ar[i] = -1;
        }
        for (int i=x+1;i<=n;i+=2){
            ar[i] = -1;
        }
        for (int i=1;i<=n;i++){
            cout << ar[i] << " \n"[i==n];
        }
    }
}