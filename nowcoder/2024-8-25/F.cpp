#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
struct haha{
    ll num,idx;
    bool operator < (const haha &that) const{
        return num > that.num;
    }
};
int main(){
    int n,m;
    cin >> n;
    vector<vector<ll>> arr(n+1);
    vector<priority_queue<haha>> mi(n+1);
    for (int i=1;i<=n;i++){
        cin >> m;
        arr[i].resize(m+1);
        for (int j=1;j<=m;j++){
            cin >> arr[i][j];
            mi[i].push({arr[i][j],j});
        }
    }
    int q,t;cin >> q;
    priority_queue<haha> temp;
    for (int i=0;i<q;i++){
        cin >> t;
        if (t == 1){
            int row,cal,x;
            cin >> row >> cal >> x;
            while (mi[row].top().idx!=cal){
                temp.push(mi[row].top());
                mi[row].pop();
            }
            mi[row].pop();
            mi[row].push({x,cal});
            while (!temp.empty()){
                mi[row].push(temp.top());
                temp.pop();
            }
        } else{
            int row;
            cin >> row;
            cout << mi[row].top().num << '\n';
        }
    }
}