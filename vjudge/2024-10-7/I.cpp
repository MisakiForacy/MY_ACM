#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
    bool operator < (const node &that) const {
        return a < that.a;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        vector<node> op(m+1);
        for (int i=1;i<=m;i++){
            cin >> op[i].a >> op[i].b;
        }
        op[0].a = op[0].b = 0;
        int ok = 1;
        sort(op.begin(),op.end());
        for (int i=1;i<=m;i++){
            if (op[i].b > op[i].a){
                ok = 0;
                break;
            }
            if (op[i].b-op[i-1].b!=op[i].a-op[i-1].a){
                if (op[i].b-op[i-1].b>op[i].a-op[i-1].a){
                    ok = 0;
                    break;
                } else if (op[i].b>=op[i].a-op[i-1].a){
                    ok = 0;
                    break;
                }
            }
        }
        ok?cout << "Yes\n":cout << "No\n";
    }
}