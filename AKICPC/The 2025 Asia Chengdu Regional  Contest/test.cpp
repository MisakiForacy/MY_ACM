#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Matrix
{
	int R, C;
	vector<vector<LL>> mat;
	Matrix(int row = 2, int cal = 2){
		R = row;
		C = cal;
		mat.resize(row, vector<LL>(cal, 0));
	}
	Matrix friend operator * (Matrix A, Matrix B){
		int r = A.R, c = B.C, x = A.C;
		Matrix C(r, c);
        for (int i = 0;i < r;i ++) {
            for (int j = 0;j < c;j ++) {
                for (int k = 0;k < x;k ++) {
                    C.mat[i][j] += A.mat[i][k] * B.mat[k][j];
                }
            }
        }
		return C;
	}
};

/*
0 1 1 0
0 0 0 2
0 0 0 1
0 0 0 0
*/ 

void solve () {
    int n, t;
    cin >> n >> t;
    LL N = n * 9;
    Matrix G(N, N);
    for (int i = 0;i < N;i += 9) {
        for (int j = 0;j < N;j += 9) {
            char x;
            cin >> x;
            G.mat[i][j] = x - '0';
        }
    }
    for (int )
}

int main () {
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}