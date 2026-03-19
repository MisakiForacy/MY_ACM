#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int h,w,q,r,c;
    cin >> h >> w >> q;
    vector<vector<int>> mp(h+1,vector<int>(w+1,1));
    vector<set<int>> H(w+1);
    vector<set<int>> W(h+1);
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            H[i].insert(j);
        }
    }
    for (int i=1;i<=w;i++){
        for (int j=1;j<=h;j++){
            W[i].insert(j);
        }
    }
    for (int i=0;i<q;i++){
        cin >> r >> c;
        if (mp[r][c]){ 
            mp[r][c] = 0;
            H[r].erase(*find(all(H[r]),c));
            W[c].erase(*find(all(W[c]),r));
        }else {
            if (*lower_bound)
            H[r].erase(*lower_bound(all(H[r]),c));
            H[r].erase(*upper_bound(all(H[r]),c));
        }
    }
    int cnt = 0;
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            if (mp[i][j]){
                cnt ++;
            }
        }
    }
    cout << cnt << '\n';
}