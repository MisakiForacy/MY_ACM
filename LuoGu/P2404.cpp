#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int nn;
void dfs(int n){
    if (!n){
        for (int i=0;i<ans.size();i++){
            cout << ans[i] << "+\n"[i==ans.size()-1];
        }
        return;
    }
    for (int i=1;i<=n/2;i++){
        if (ans.empty()||i>=ans.back()){
            ans.push_back(i);
            dfs(n-i);
            ans.pop_back();
        }
    }
    if (n != nn){
        ans.push_back(n);
        dfs(0);
        ans.pop_back();
    }
}
int main(){
    int n;
    cin >> n;
    nn = n;
    dfs(n);
}