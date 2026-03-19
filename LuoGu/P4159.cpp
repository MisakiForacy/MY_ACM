#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int MOD = 2009;

/**
 * #矩阵快速幂
 * 邻接矩阵的幂(k)可以表示从点i(行)出发到达点j(列)经过k步的通路数量
 * 
 * 洛谷P4159
 * n点稠密图，边权1~9，0代表无边，
 * 求从点1开始累计边权为t的到达点n的方案数
 * n<=10
 * t<=1e9
 */

struct Matrix
{
    int R, C;
    vector<vector<LL>> mat;
    Matrix(int r_ = 1, int c_ = 1, int val = 0) {
        this->R = r_;
        this->C = c_;
        mat.resize(r_, vector<LL> (c_, val));
    }
    Matrix friend operator * (Matrix A, Matrix B) {
        int r = A.R, c = B.C, x = A.C;
        Matrix C(r, c);
        for (int i = 0;i < r;i ++) {
            for (int j = 0;j < c;j ++) {
                for (int k = 0;k < x;k ++) {
                    C.mat[i][j] += A.mat[i][k] * B.mat[k][j] % MOD;
                    C.mat[i][j] %= MOD;
                }
            }
        }
        return C;
    }
};

void solve () {
    int n, t;
    cin >> n >> t;
    int N = n * 10;
    Matrix A(N, N);
    for (int i = 0;i < N;i += 10) {
        for (int j = 0;j < N;j += 10) {
            char c;
            cin >> c;
            A.mat[i][j] = c - '0';
            if (A.mat[i][j] > 1) {
                int use = A.mat[i][j] - 1;
                A.mat[i][j] = 0;
                for (int k = 0;k < use;k ++) {
                    A.mat[i + k][i + k + 1] = 1;
                }
                A.mat[i + use][j] = 1;
            }
        }
    }
    auto qpow = [&](int k) -> Matrix {
        Matrix res(N, N);
        for (int i = 0;i < N;i ++) res.mat[i][i] = 1;
        while (k) {
            if (k & 1) res = res * A;
            A = A * A;
            k >>= 1;
        }
        return res;
    };
    Matrix Res = qpow(t);
    LL ans = Res.mat[0][(n - 1) * 10];
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}

/*
2 2
02
00

相对目标点静止的矩阵    X
0 0 0 1
0 0 0 0
0 0 0 0
0 0 1 0

相对出发点静止的矩阵    √
0 1 0 0
0 0 1 0
0 0 0 0
0 0 0 0

*/