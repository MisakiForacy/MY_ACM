#include <bits/stdc++.h>
using namespace std;
struct haha{
    int h,v;
};
int main(){
    int n;
    cin >> n;
    vector<haha> a(n+1);
    vector<int> pre(n+1), suf(n+1);
    vector<int> ans(n+1,0);
    stack<int> stk;
    for (int i=1;i<=n;i++){
        cin >> a[i].h >> a[i].v;
    }
    for (int i=n;i>=1;i--){
        while (!stk.empty() && a[stk.top()].h<=a[i].h){
            stk.pop();
        }
        pre[i] = stk.empty()?0:stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i=1;i<=n;i++){
        while (!stk.empty() && a[stk.top()].h<=a[i].h){
            stk.pop();
        }
        suf[i] = stk.empty()?0:stk.top();
        stk.push(i);
    }
    int mx = LLONG_MIN;
    for (int i=1;i<=n;i++){
        ans[pre[i]] += a[i].v;
        ans[suf[i]] += a[i].v;
    }
    for (int i=1;i<=n;i++){
        mx = max(mx,ans[i]);
    }
    cout << mx << '\n';
}