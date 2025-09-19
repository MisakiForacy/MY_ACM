#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int mp[N][N];
int var[N];
int n,m,x,u,v;

void init(){
    memset(mp,0,sizeof(mp));
    memset(var,0,sizeof(var));
}

void dfs(int u){
    cout << u << ' ';
    var[u] = 1;
    for (int i=1;i<=n;i++){
        if (!var[i] && mp[u][i]){
            dfs(i);
        }
    }
}

queue<int>Q;
void bfs(int u){
    Q.push(u);
    var[u] = 1;
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        cout << now << ' ';
        for (int i=1;i<=n;i++){
            if (!var[i] && mp[now][i]){
                Q.push(i);
                var[i] = 1;
            }
        }
    }
}

int main(){
    cin >> n >> m >> x;
    memset(mp,0,sizeof(mp));
    for (int i=0;i<m;i++){
        cin >> u >> v;
        mp[u][v] = 1;
        // mp[v][u] = 1;
    }
    memset(var,0,sizeof(var));
    dfs(x);
    memset(var,0,sizeof(var));
    cout << '\n';
    bfs(x);
}