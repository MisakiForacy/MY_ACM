#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1,0),f(n+1,0);
    int Max = 0, id = -1;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (a[i] > Max){
            Max = a[i];
            id = i;
        }
    }
    a.push_back(INT_MAX);
    if (k >= n){
        cout << id << '\n';
    } else{
        stack<int> stk;
        for (int i=n+1;i>=1;i--){
            while (!stk.empty() && a[stk.top()]<=a[i]){
                stk.pop();
            }
            f[i] = stk.empty()?0:stk.top();
            stk.push(i);
        }
        map<int,int> mp;
        for (int i=1;i<=n;i++){
            mp[f[i]] ++;
            if (f[i]-i>=k || f[i]-i==n-i+1){
                cout << i << '\n';
                break;
            }
            if (mp[f[i]]>=k){
                cout << f[i] << '\n';
                break;
            }
        }
    }
}