#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>matrix;
static inline void f(int n,int y,int x);

int main(){
    int n,nn;
    cin >> n;
    nn = 1<<n;
    matrix.resize(nn,vector<int>(nn,1));
    f(nn,0,0);
    for(int i=0;i<nn;i++){
        for(int j=0;j<nn;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

static inline void f(int n,int y,int x){
    if(!n)return;
    for(int i=y;i<y+n/2;i++){
        for(int j=x;j<x+n/2;j++){
            matrix[i][j] = 0;
        }
    }
    f(n/2,y+n/2,x);
    f(n/2,y,x+n/2);
    f(n/2,y+n/2,x+n/2);
}