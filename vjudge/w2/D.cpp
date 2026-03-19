#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,ok = 1;
    cin >> n >> m;
    map<int,int>mp;
    for (int i=0;i<m;i++){
        cin >> x;
        mp[x] ++;
    }
    for (int i=0;i<n;i++){
        if (!mp[i]){
            cout << i << " \n"[i==n-1];
            ok = 0;
        }
    }
    if (ok){
        cout << n << '\n';
    }
}