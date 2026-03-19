#include <bits/stdc++.h>
using namespace std;
vector<vector<char>>mat(9,vector<char>(9));
int main(){
    int T;
    cin >> T;
    while (T --){
        for (int i=0;i<9;i++){
            getchar();
            for (int j=0;j<9;j++){
                mat[i][j]=getchar();
                if (mat[i][j]=='2'){
                    mat[i][j]='1';
                }
            }
        }
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                cout << mat[i][j];
            }cout << '\n';
        }
    }
}