#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> G[N];
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int u, v;
    vector<int> nd(n+1);
    for (int i=0;i<n;i++){
        nd[i+1] = s[i]=='R';
    }
    cnt = 0;
    for (int i=0;i<n-1;i++){
        cin >> u >> v;
        if (nd[u]==nd[v]){
            cnt ++;
        }
    }
    cout << cnt << '\n';
}