#include <bits/stdc++.h>
using namespace std;
int r,c,k;
vector<vector<int>>mp;
bool checkx(int x,int y,int k){
    for (int i=x;i<x+k;i++){
        if (!(mp[y][i])) return 0;
    }
    return 1;
}
bool checky(int x,int y,int k){
    for (int i=y;i<y+k;i++){
        if (!(mp[i][x])) return 0;
    }
    return 1;
}
int main(){
    int p = 0;
    string s;
    cin >> r >> c >> k;
    mp.resize(r,vector<int>(c));
    for (int i=0;i<r;i++){
        cin >> s;
        for (int j=0;j<c;j++){
            mp[i][j] = (s[j]=='.');
        }
    }
    for (int i=0;i<r;i++){
        for (int j=0;j<=c-k;j++){
            if (mp[i][j]){
                p += checkx(j,i,k);
            }
        }
    }
    for (int i=0;i<=r-k;i++){
        for (int j=0;j<c;j++){
            if (mp[i][j]){
                p += checky(j,i,k);
            }
        }
    }
    if (k==1) p /= 2;
    cout << p << '\n';
}