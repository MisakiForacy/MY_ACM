#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct node{
    int id, s, d, c;
    bool operator < (const node &that) const {
        return d - c > that.d - that.c;
    }
};
int main(){
    int D,n;
    cin >> D >> n;
    vector<int> ans(D + 1, 0);
    priority_queue<node> Q;
    for (int i = 1;i <= n;i ++){
        int s,d,c;
        cin >> s >> d >> c;
        Q.push({i,s,d,c});
        ans[d] = n + 1;
    }
    int ok = 1;
    for (int i = 1;i <= D;i ++){
        vector<node> tmp;
        if (!ans[i]){
            while (Q.size()){
                if (Q.top().d < i){
                    ok = 0;
                    break;
                }
                if (Q.top().s > i){
                    tmp.push_back(Q.top());
                    Q.pop();
                } else{
                    node tp = Q.top();
                    Q.pop();
                    tp.c --;
                    ans[i] = tp.id;
                    if (tp.c) Q.push(tp);
                    break;
                }
            }
        }
        while (tmp.size()){
            Q.push(tmp.back());
            tmp.pop_back();
        }
    }
    if (Q.size()) ok = 0;
    if (ok){
        for (int i = 1;i <= D;i ++){
            cout << ans[i] << " \n"[i == D];
        }
    } else{
        cout << -1 << '\n';
    }
}