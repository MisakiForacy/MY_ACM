#include <bits/stdc++.h>                                                                                                                
using namespace std;                                                                                                                
using LL = long long;                                                                                                               
const LL N = 2e5+10;                                                                                                                
vector<LL> G[N];                                                                                                                
int main(){                                                                                                             
    LL n,m,k,u,v,x;                                                                                                             
    cin >> n >> m >> k;                                                                                                             
    vector<bool> bz(n+1,0);                                                                                                             
    vector<bool> in(n+1,0);                                                                                                             
    for (LL i=0;i<k;i++){                                                                                                               
        cin >> x;                                                                                                               
        bz[x] = 1;
    }
    for (LL i=0;i<m;i++){                                                                                                               
        cin >> u >> v;                                                                                                              
        G[u].push_back(v);                                                                                                              
        G[v].push_back(u);                                                                                                              
    }                                                                                                               
    queue<LL> q;                                                                                                                
    for (LL i=1;i<=n;i++){                                                                                                              
        if (!bz[i]){                                                                                                                
            q.push(i);                                                                                                              
            break;                                                                                                              
        }                                                                                                               
    }                                                                                                               
    // map<LL,vector<LL>> ans;      
    vector<vector<LL>> ans;       
    vector<int> st;                                                                                                
    while (!q.empty()){                                                                                                             
        LL t = q.front();                                                                                                               
        q.pop();                                                                                                                
        in[t] = 1;                                                                                                              
        if (!bz[t]){                                                                                                                
            vector<LL> c;                                                                                                               
            for (LL i=0;i<G[t].size();i++){                                                                                                             
                if (!in[G[t][i]]){                                                                                                              
                    c.push_back(G[t][i]);                                                                                                               
                    if (!bz[G[t][i]]){                                                                                                              
                        q.push(G[t][i]);                                                                                                                
                    }                                                                                                               
                    in[G[t][i]] = 1;                                                                                                                
                }                                                                                                               
            }
            if (c.size()){
                ans.push_back(c);
                st.push_back(t);
            }                                                                                                          
        }                                                                                                               
    }                                                                                                               
    LL ok = 1;                                                                                                              
    for (LL i=1;i<=n;i++){                                                                                                              
        if (!in[i]){                                                                                                                
            ok = 0;                                                                                                             
            break;                                                                                                              
        }                                                                                                               
    }                                                                                                               
    if (ok){                                                                                                                
        cout << "Yes\n";                                                                                                                
        cout << ans.size() << '\n';                                                                                                             
        for (int i=0;i<st.size();i++){
            cout << st[i] << ' ' << ans[i].size() << ' ';
            for (int j=0;j<ans[i].size();j++){
                cout << ans[i][j] << " \n"[j==ans[i].size()-1];
            }
        }                                                                                                              
    } else{                                                                                                             
        cout << "No\n";                                                                                                             
    }                                                                                                               
}                                                                                                               