#include <bits/stdc++.h>
#define debug(x) cerr << #x << ':' << x << '\n'
using namespace std;
double check(string s){
    // cout << "haha" << '\n';
    // s.erase(0,1);
    cout << s << '\n';
    
    int m = s.length();
    cout << m << '\n';
    vector<int>pre(m+1,0);
    for (int i=1;i<=m;i++){
        pre[i] = (s[i-1]=='1'?1:0);
        pre[i] = pre[i] + pre[i-1];
        // cout << pre[i] << " \n"[i==m];
    }
    for (int i=0;i<m;i++){
        if (s[i]=='0'&&s[i+1]=='1'){
            if ((m-i)/2 < pre[m]-pre[i]){
                // debug(s);
                // debug(pre[i]-pre[0]);
                return 1.0*(pre[i]-pre[0])/i;
            }
        }
    }
    // debug(m);
    // debug((pre[m]-pre[0]));
    return 1.0*(pre[m]-pre[0])/m;
}
string dfs(vector<vector<int>>tree,vector<pair<int,double>>&node,int now,int r){
    string s = "";
    if (tree[now].empty()) return (node[now].first?"1":"0");
    for (int i=0;i<int(tree[now].size());i++){
        s += dfs(tree,node,tree[now][i],!r);
    }
    // cout << s << '\n';
    node[now].second = check(s);
    double mx = 0, mi = 1;
    if (r){
        int idx = 0;
        for (int i=0;i<int(tree[now].size());i++){
            node[tree[now][i]].second = check(s);
            // mx = max(mx,node[tree[now][i]].second);
            if (mx < node[tree[now][i]].second){
                mx = node[tree[now][i]].second;
                idx = i;
            }
        }
        cout << (node[idx].first?"1":"0") << '\n'; 
        return (node[idx].first?"1":"0");
        node[now].second = mx;
        // cout << r << ':';
        // debug(mx);
    } else{
        int idx = 0;
        for (int i=0;i<int(tree[now].size());i++){
            node[tree[now][i]].second = check(s);
            // mi = min(mi,node[tree[now][i]].second);
            if (mi > node[tree[now][i]].second){
                mi = node[tree[now][i]].second;
                idx = i;
            }
        }
        cout << (node[idx].first?"1":"0") << '\n'; 
        return (node[idx].first?"1":"0");
        node[now].second = mi;
    }
    cout << s << '\n';
    return s;
}
int main(){
    cout << fixed << setprecision(9);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<vector<int>>tree(n+1);
        vector<pair<int,double>>node(n+1,{-1,0});
        int x,y,k;
        for (int i=0;i<n-1;i++){
            cin >> x >> y >> k;
            tree[x].push_back(y);
            node[y].first = k;
        }
        int ok = 1;
        for (int i=0;i<int(tree[1].size());i++){
            if (node[tree[1][i]].first){
                ok = 0;
                break;
            }
        }
        if (ok){
            cout << 0 << '\n';
        } else{
            dfs(tree,node,1,1);
            cout << node[1].second << '\n';
        }
    }
}