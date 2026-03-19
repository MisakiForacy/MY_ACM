#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> a;
int n,k;
bool check(vector<int>a,int k){
    int sum = 0;
    for (int i=0;i<int(a.size());i++){
        sum += a[i];
    }
    return (sum%k==0);
}
void dfs(int idx,int k){
    if (!idx){
        if (check(ans,k)){
            for (int i=0;i<int(ans.size());i++){
                cout << ans[i] << " \n"[i==int(ans.size())-1];
            }
        }
        return;
    }
    for (int i=1;i<=a[n-idx];i++){
        ans[n-idx] = i;
        dfs(idx-1,k);
    }
    return;
}
int main(){
    cin >> n >> k;
    a.resize(n);
    ans.resize(n);
    for (int i=0;i<n;i++) cin >> a[i];
    dfs(n,k);
}
