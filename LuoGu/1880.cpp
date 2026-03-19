#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(2*n+1,0), pre(2*n+1,0);
    vector<vector<int>> mi(2*n+1,vector<int>(2*n+1,INT_MAX));
    vector<vector<int>> mx(2*n+1,vector<int>(2*n+1,0));
    for (int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
        mi[i][i] = 0;
    }
    for (int i=n+1;i<=2*n;i++){
        pre[i] = pre[i-1] + a[i-n];
        mi[i][i] = 0;
    }
    for (int l=2;l<=n;l++){
        for (int i=1;i+l-1<=2*n;i++){
            int j = i + l - 1;
            for (int k=i;k<j;k++){
                mi[i][j] = min(mi[i][j],mi[i][k]+mi[k+1][j]+pre[j]-pre[i-1]);
                mx[i][j] = max(mx[i][j],mx[i][k]+mx[k+1][j]+pre[j]-pre[i-1]);
            }
        }
    }
    int Min = INT_MAX;
    int Max = 0;
    for (int i=1;i<=n+1;i++){
        Min = min(Min,mi[i][i+n-1]);
        Max = max(Max,mx[i][i+n-1]);
    }
    cout << Min << '\n';
    cout << Max << '\n';
}