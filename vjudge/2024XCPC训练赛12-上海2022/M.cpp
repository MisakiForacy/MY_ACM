#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
const int N = 1e4+10;
vector<string> cut(string s){
    vector<string> a;
    a.push_back("#");
    for (int j=0;j<s.length();j++){
        if (s[j] == '/'){
            a.push_back(s.substr(0,j));
        }
    }
    string ss = s.substr(0,s.length());
    ss.push_back('#');
    a.push_back(ss);
    return a;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        vector<int> G[N];
        int res[N],vis[N];
        for (int i=0;i<N;i++) res[i] = 0, vis[i] = 0;
        int n,m;
        cin >> n >> m;
        int cnt = 1;
        map<string,int> mp;
        mp["#"] = cnt;
        for (int i=0;i<n;i++){
            string s;
            cin >> s;
            vector<string> a = cut(s);
            for (int j=1;j<a.size();j++){
                if (!mp.count(a[j])){
                    cnt ++;
                    mp[a[j]] = cnt;
                }
                G[mp[a[j-1]]].push_back(mp[a[j]]);
            }
        }
        for (int i=0;i<m;i++){
            string s;
            cin >> s;
            vector<string> a = cut(s);
            for (int j=1;j<a.size();j++){
                if (!mp.count(a[j])){
                    cnt ++;
                    mp[a[j]] = cnt;
                }
                int ok = 1;
                res[mp[a[j]]] = 1;
                G[mp[a[j-1]]].push_back(mp[a[j]]);
            }
        }
        LL ans = 0;
        queue<int> Q;
        Q.push(1);
        while (!Q.empty()){
            int x = Q.front();
            Q.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            for (int i=0;i<G[x].size();i++){
                if (!res[G[x][i]] && !vis[G[x][i]]){
                    ans ++;
                    vis[G[x][i]] = 1;
                } else if (!vis[G[x][i]]){
                    Q.push(G[x][i]);
                }
            }
        }
        cout << ans << '\n';
    }
}