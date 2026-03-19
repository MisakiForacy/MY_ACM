#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> timeline;
bool check(int id,int start,int len){
    for (int i=start;i<start+len;i++){
        if (timeline[id][i]) return 0;
    }
    return 1;
}
int main(){
    int m,n;
    cin >> m >> n;
    vector<int> a(m*n);
    vector<vector<int>> step(n+1,vector<int>(m+1)),time(n+1,vector<int>(m+1));
    timeline.resize(m+1,vector<int>(2e5,0)); 
    for (int i=0;i<m*n;i++) cin >> a[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> step[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> time[i][j];
    map<int,int> ed,st;
    for (int i=0;i<n*m;i++){
        st[a[i]] ++;
        int id = step[a[i]][st[a[i]]];
        int start = ed[a[i]];
        int len = time[a[i]][st[a[i]]];
        for (int k=start;k<2e5;k++){
            if (check(id,k,len)){
                for (int j=k;j<k+len;j++){
                    timeline[id][j] = 1;
                }
                ed[a[i]] = k + len;
                break;
            }
        }
    }
    int mx = 0;
    for (int i=1;i<=n;i++){
        mx = max(mx,ed[i]);
    }
    cout << mx << '\n';
}