#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5 + 10;
vector<int> G[N];
int main(){
    int T;
    cin >> T;
    while (T --){
        int n, cnt = 0;
        cin >> n;
        for (int i = 1;i <= n;i ++){
            G[i].clear();
        }
        for (int i = 2;i <= n;i ++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 1;i <= n;i ++){
            if (G[i].size() == 1) cnt ++;
        }
        cout << (cnt + 1) / 2 << '\n';
    }
}