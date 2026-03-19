#include <bits/stdc++.h>
using namespace std;
vector<int>Set;
int findx(int x) {
    if (Set[x] != x) {
        Set[x] = findx(Set[x]);
    }
    return Set[x];
}
void merge(int a,int b) {
    Set[a] = b;
}
int main(){
    int n,m;
    cin >> n >> m;
    Set.resize(n+1,0);
    vector<int>a(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        Set[i] = i;
    }
    int u,v;
    for (int i=0;i<m;i++){
        cin >> u >> v;
        merge(findx(max(u,v)),findx(min(u,v)));
    }
    map<int,map<int,int>>mp;
    map<int,int>cnt;
    for (int i=1;i<=n;i++){
        mp[Set[i]][a[i]] ++;
        cnt[Set[i]] ++;
    }
    // for (int i=1;i<=n;i++){
    //     cout << Set[i] << " \n"[i==n];
    // }
    int mx = 0, ai;
    for (auto c:mp){
        // cout << c.first << ":\n";
        for (auto x:c.second){
            // cout << x.first << ' ' << x.second << '\n';
            if (x.second > mx){
                mx = x.second;
                ai = c.first;
            }
        }
    }
    if (cnt[ai] > 1) mx ++;
    cout << mx << '\n';
}