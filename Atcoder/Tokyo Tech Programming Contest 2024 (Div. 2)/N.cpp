#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5+10;
vector<int> G[N];
int main(){
    int n,u,v;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}