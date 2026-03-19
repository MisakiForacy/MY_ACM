#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ok = 1;
    cin >> n >> m;
    vector<int>a(m);
    vector<vector<int>>mp(n,vector<int>(m,0));
    for (int i=0;i<m;i++){
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> mp[i][j];
            a[j] -= mp[i][j];
        }
    }
    for (int i=0;i<m;i++){
        if (a[i] > 0){
            ok = 0;
        }
    }
    cout << (ok?"Yes\n":"No\n");
}