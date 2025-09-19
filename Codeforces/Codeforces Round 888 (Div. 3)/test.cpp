#include <bits/stdc++.h>
using LL = long long;
using namespace std;
const int N = 105;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<int> in(n + 1, 0);
    for (int i = 1;i <= m;i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in[v] ++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!in[i]) q.push(i);
    }
    while (q.size()){
        int u = q.front();
        q.pop();
        for (auto v : g[u]){
            in[v] --;
            if (!in[v]) q.push(v);
        }
    }
    
}