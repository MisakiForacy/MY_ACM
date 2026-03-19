#include <bits/stdc++.h>
#define N 100000
using namespace std;
char A[N], B[N];
char a,b;
char P[5][5] = {'.','.','#','.','.','.','#','.','#','.','#','.','.','.','#','.','#','.','#','.','.','.','#','.','.'};
char W[5][5] = {'.','.','*','.','.','.','*','.','*','.','*','.','.','.','*','.','*','.','*','.','.','.','*','.','.'};
int main(){
    int len,ii,i,j,t;
    string n;
    cin >> n;
    len = n.length();
    vector<vector<char>>matrix(5,vector<char>(5+(len-1)*4,'.'));
    i = 0;
    for(t=0;t<len;t++){
        for(i=t*4;i<t*4+5;i++){
            for(j=0;j<5;j++){
                if((t+1)%3){
                    matrix[j][i] = P[j][i-t*4];
                }
            }
        }
    }
    for(t=0;t<len;t++){
        for(i=t*4;i<t*4+5;i++){
            for(j=0;j<5;j++){
                if(!((t+1)%3)){
                    matrix[j][i] = W[j][i-t*4];
                }
            }
        }
    }
    matrix[2][2] = n[0];
    ii = 1;
    for(int i=6;i<5+(len-1)*4;i+=4){
        matrix[2][i] = n[ii];
        ii++;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5+(len-1)*4;j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}