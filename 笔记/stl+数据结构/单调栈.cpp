#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1),f(n+1);
    stack<int> stk;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=n;i>=1;i--){
        while (!stk.empty() && a[stk.top()]<=a[i]){
            stk.pop();
        }
        f[i] = stk.empty()?0:stk.top();
        stk.push(i);
    }
    for (int i=1;i<=n;i++){
        cout << f[i] << " \n"[i==n];
    }
}