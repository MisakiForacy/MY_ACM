#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 500;
int main(){
    struct node{
        int s,w;
    };
    int T;
    cin >> T;
    while (T--){
        vector<node> G[N];
        int n,m,p,u,v,w;
        cin >> n >> m >> p;
        vector<int> s(p);
        for (int i=0;i<p;i++) cin >> s[i];
        for (int i=0;i<m;i++){
            cin >> u >> v >> w;
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        
    }
}