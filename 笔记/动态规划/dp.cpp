#include <bits/stdc++.h>
using namespace std;
int w[101],v[1001];
int cut[101][1001];
int f(int i,int j) {
    if (cut[i][j]) return cut[i][j];
    if (!i) return 0;
    if (j<w[i]) {
        int ma = f(i-1,j);
        cut[i][j] = ma;
        return ma;
    }
    int ma = max(f(i-1,j),f(i-1,j-w[i])+v[i]);
    cut[i][j] = ma;
    return ma; 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> w[i] >> v[i];
    }
    cout << f(m,n) << '\n';
}