#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int G[N];
int main(){
    int n,m,u,v;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> u >> v;
        G[u] = v;
        G[v] = u;
    }
    
}