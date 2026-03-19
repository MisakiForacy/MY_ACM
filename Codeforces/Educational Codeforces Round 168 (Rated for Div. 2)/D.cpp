#include <bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int,vector<int>>>&tree,int idx){
    for (int )
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<int>a(n+1);
        vector<int>p(n+1);
        vector<pair<int,vector<int>>>tree(n);
        for (int i=1;i<=n;i++) cin >> a[i];
        tree[1] = a[0];
        for (int j=2;j<=n;j++){
            cin >> p[j];
            tree[p[j]].second.push_back(a[j]);
        }
        dfs(tree,1);
    }
}