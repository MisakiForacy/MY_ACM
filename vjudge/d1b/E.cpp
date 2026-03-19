#include <bits/stdc++.h>
using namespace std;



int main(){
    int n,mx=0;
    cin >> n;
    vector<vector<int>>mp(n,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            int num = check(i,j);
            mx = max(mx,num);
        }
    }
    cout << mx << '\n';
}