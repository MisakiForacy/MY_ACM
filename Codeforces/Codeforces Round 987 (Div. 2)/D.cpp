#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        vector<int> pre(n+1,0), suf(n+1,0);
        for (int i=1;i<=n;i++) cin >> a[i];
        stack<int> stk;
        for (int i=n;i>=1;i--){
            while (!stk.empty() && a[stk.top()]<=a[i]){
                stk.pop();
            }
            pre[i] = stk.empty()?0:stk.top();
            stk.push(i);
        }
        for (int i=1;i<=n;i++){
            while (!stk.empty() && a[stk.top()]>=a[i]){
                stk.pop();
            }
            suf[i] = stk.empty()?0:stk.top();
            stk.push(i);
        }
    }
}