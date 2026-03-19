#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int cnt = 0;
    for (int i=0;i<m;i++){
        int l;
        cin >> l;
        int st = 0, ed = 0;
        int c;
        for (int j=0;j<l;j++){
            cin >> c;
            if (c==a){
                st = 1;
            }
            if (st && c==b){
                ed = 1;
            }
        }
        if (ed) cnt ++;
        // cout << cnt << '\n';
    }
    cout << cnt << '\n';
}