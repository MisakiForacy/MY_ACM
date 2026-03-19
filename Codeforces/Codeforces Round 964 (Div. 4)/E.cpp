#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin >> T;
    vector<int>pre(2e5+10,0);
    pre[0] = 0;
    for (int i=1;i<2e5+10;i++){
        pre[i] = pre[i/3] + 1;
    }
    for (int i=1;i<2e5+10;i++){
        pre[i] = pre[i-1] + pre[i];
    }
    while (T--){
        int l,r;
        cin >> l >> r;
        cout << pre[r] - 2*pre[l-1] + pre[l] << '\n';
    }
}