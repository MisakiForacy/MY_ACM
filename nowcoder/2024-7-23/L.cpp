#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<char>>mp(9,vector<char>(9));
    for (int i=0;i<9;i++){
        string s;
        cin >> s;
        for (int j=0;j<9;j++){
            mp[i][j] = s[j];
        }
    }
    int xx, yy;
    for (int i=1;i<8;i++){
        for (int j=1;j<8;j++){
            if (mp[i][j]=='8'){
                xx = j;
                yy = i;
                goto l;
            }
        }
    }
    l:;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (i==yy&&j==xx){
                cout << mp[i][j];
            } else{
                cout << '*';
            }
        }
        cout << '\n';
    }
}