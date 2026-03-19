#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> G[N];
int vis[N];
struct haha{
    int node,step;
};
int main(){
    int n,k,u,v;
    cin >> n >> k;
    for (int i=0;i<n-1;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int x,kk;
    kk = k;
    map<int,int> mp;
    vector<int> ls(k);
    for (int i=0;i<k;i++){
        cin >> ls[i];
        mp[ls[i]] = 1;
    }
    queue<haha> Q;
    Q.push({ls[0],1});
    mp[ls[0]] = 0;
    vis[ls[0]] = 1;
    kk --;
    int ans;
    while (!Q.empty() && kk){
        int nd = Q.front().node;
        int st = Q.front().step;
        Q.pop();
        for (int i=0;i<G[nd].size();i++){
            if (!vis[G[nd][i]]){
                Q.push({G[nd][i],st+1});
                if (mp[G[nd][i]]){
                    mp[G[nd][i]] = 0;
                    kk --;
                }
                if (!kk){
                    ans = st+1;
                }
                vis[G[nd][i]] = 1;
            }
        }
    }
    cout << ans << '\n';
}