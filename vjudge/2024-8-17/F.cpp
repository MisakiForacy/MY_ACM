#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    k = k%4;
    vector<vector<int>> mp(n+1,vector<int>(n+1));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    if (k==0){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout << mp[i][j] << " \n"[j==n-1];
            }
        }
    } else if (k==1){
        for (int i=0;i<n;i++){
            for (int j=n-1;j>=0;j--){
                cout << mp[j][i] << " \n"[j==0];
            }
        }
    } else if (k==2){
        for (int i=n-1;i>=0;i--){
            for (int j=n-1;j>=0;j--){
                cout << mp[i][j] << " \n"[j==0];
            }
        }
    } else{
        for (int i=n-1;i>=0;i--){
            for (int j=0;j<n;j++){
                cout << mp[j][i] << " \n"[j==n-1];
            }
        }
    }
}