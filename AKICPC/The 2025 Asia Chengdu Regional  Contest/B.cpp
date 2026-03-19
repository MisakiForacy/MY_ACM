#include <bits/stdc++.h>
using namespace std;
using LL = long long;

#define LOG 40

const LL inf = 1e18;

struct Matrix
{
	int R, C;
	vector<vector<LL>> mat;
	Matrix(int row = 2, int cal = 2){
		R = row;
		C = cal;
		mat.resize(row, vector<LL>(cal, -inf));
	}
	Matrix friend operator * (Matrix A, Matrix B){
		int r = A.R, c = B.C, x = A.C;
		Matrix C(r, c);
        for (int i = 0;i < r;i ++) {
            for (int j = 0;j < c;j ++) {
                for (int k = 0;k < x;k ++) {
                    if (A.mat[i][k] == - inf || B.mat[k][j] == - inf) continue;
                    C.mat[i][j] = max(C.mat[i][j], A.mat[i][k] + B.mat[k][j]);
                }
            }
        }
		return C;
	}
};
 
void solve () {
    LL n, m, K, R;
    cin >> n >> m >> K >> R;
    vector<LL> a(n, 0), c(n, 0), A(1LL << n, 0), C(1LL << n, 0);
    for (int i = 0;i < n;i ++) cin >> a[i] >> c[i];
    for (int T = 0;T < 1LL << n;T ++) {
        for (int j = 0;j < n;j ++) {
            if (!(T >> j & 1)) continue;
            A[T] += a[j];
            C[T] += c[j];
        }
    }
    
    auto qmi = [&](Matrix f, LL k) -> Matrix {
        Matrix res(1LL << n, 1LL << n);
        for (int i = 0;i < 1LL << n;i ++) res.mat[i][i] = 0;
        while (k) {
            if (k & 1) res = res * f;
            f = f * f;
            k >>= 1;
        }
        return res;
    };

    Matrix base(1LL << n, 1LL << n);
    for (int T = 0;T < 1LL << n;T ++) {
        for (int T_ = 0;T_ < 1LL << n;T_ ++) {
            LL cost = C[T_] + __builtin_popcount(T & T_) * K;
            if (cost <= m) base.mat[T][T_] = A[T_];
        }
    }

    base = qmi(base, R - 1);

    Matrix dp(1, 1LL << n);
    for (int T = 0;T < 1LL << n;T ++) if (C[T] <= m) dp.mat[0][T] = A[T];

    dp = dp * base;

    LL ans = 0;

    for (int T = 0;T < 1LL << n;T ++) ans = max(ans, dp.mat[0][T]);

    cout << ans << '\n';
}

/*
3
3 7 1 5
59 3
13 2
81 4
5 14 2 9
66 8
20 2
25 4
39 6
57 7
4 13 7 16
18 2
13 5
33 4
7 1
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}