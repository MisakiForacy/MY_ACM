#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define x first
#define y second
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

struct Matrix{
   int R, C;
   vector<vector<LL>> mat;
   Matrix(int row = 2, int cal = 2){
      R = row;
      C = cal;
      mat.resize(row + 1, vector<LL>(cal + 1, 0));
   }
   Matrix friend operator * (Matrix A, Matrix B){
      int r = A.R;
      int c = B.C;
      int x = A.C;
      Matrix C(r, c);
      for (int i = 1;i <= r;i ++){
         for (int j = 1;j <= c;j ++){
            for (int k = 1;k <= x;k ++){
               C.mat[i][j] += A.mat[i][k] * B.mat[k][j];
            } 
         }
      }
      return C;
   }
};

void fxy_ac(){
    Matrix mat(4, 4), A(4, 4);
    mat.mat[1][1] = mat.mat[1][2] = mat.mat[1][3] = 1;
    mat.mat[2][1] = mat.mat[2][3] = 1;
    mat.mat[3][1] = mat.mat[3][4] = 1;
    mat.mat[4][1] = 1;
    A.mat[1][1] = A.mat[2][2] = A.mat[3][3] = A.mat[4][4] = 1;
    A = A * mat;
    A = A * mat;
    A = A * mat;
    for (int i = 1;i <= 4;i ++){
        for (int j = 1;j <= 4;j ++){
            cout << A.mat[i][j] << " \n"[j == 4];
        }
    }
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 多测
    while (T --){
        fxy_ac();
        // brute();
    }
}