#include <bits/stdc++.h>
using namespace std;
void f(vector<vector<int>>&mp,int x,int y,int n){
    if (n==1){
        for (int i=x;i<x+3;i++) mp[y][i] = 1;
        mp[y+1][x] = 1, mp[y+1][x+2] = 1;
        for (int i=x;i<x+3;i++) mp[y+2][i] = 1;
        return;
    }
    for (int i=0;i<3;i++) f(mp,x+i*pow(3,n-1),y,n-1);
    f(mp,x,y+pow(3,n-1),n-1), f(mp,x+2*pow(3,n-1),y+pow(3,n-1),n-1);
    for (int i=0;i<3;i++) f(mp,x+i*pow(3,n-1),y+2*pow(3,n-1),n-1);
    return;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>>mp(pow(3,n)+1,vector<int>(pow(3,n)+1,0));
    if (n){
        f(mp,1,1,n);
        for (int i=1;i<=pow(3,n);i++){
            for (int j=1;j<=pow(3,n);j++){
                cout << (mp[i][j]?"#":".");
            }
            cout << '\n';
        }
    } else{
        cout << '#' << '\n';
    }
}