#include <bits/stdc++.h>
using namespace std;
struct info{
    int id,s;
};
bool cmp(info a,info b){
    return a.s > b.s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m,a,b,x,flg = 1;
    cin >> n >> m >> a >> b;
    vector<info>so(n),fav(n);
    for (int i=0;i<a;i++){
        for (int j=0;j<n;j++){
            cin >> x;
            so[j].s += x;
            so[j].id = j+1;
            if (i==b-1){
                fav[j].s = x;
                fav[j].id = j+1;
            }
        }
    }
    sort(so.begin(),so.end(),cmp);
    sort(fav.begin(),fav.end(),cmp);
    vector<int>ans;
    for (int i=0;i<m;i++){
        if (so[i].id == fav[0].id){
            flg = 0;
        } else{
            ans.push_back(so[i].id);
        }
    }
    if (flg){
        for (int i=0;i<m-1;i++){
            cout << ans[i] << ' ';
        }
        cout << fav[0].id << '\n';
    } else{
        cout << fav[0].id << ' ';
        for (int i=0;i<m-1;i++){
            cout << ans[i] << " \n"[i==m-1];
        }
    }
}