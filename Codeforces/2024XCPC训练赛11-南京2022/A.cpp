#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    map<char,pair<int,int>> f;
    f['U'] = {0,-1}, f['D'] = {0,1};
    f['L'] = {-1,0}, f['R'] = {1,0};
    int T;
    cin >> T;
    while (T--){
        int n,m,k;
        string s;
        cin >> n >> m >> k;
        cin >> s;
        vector<int> raw(n+2,0), cal(m+2,0);
        int lo_r = 1, hi_r = n+1;
        int lo_c = 1, hi_c = m+1;
        cal[1] = 1, cal[m+1] = -1;
        raw[1] = 1, raw[n+1] = -1;
        for (int i=0;i<s.length();i++){
            if (s[i] == 'U'){
                raw[lo_r] -= 1;
                lo_r = max(1,lo_r - 1);
                raw[lo_r] += 1;
                raw[hi_r] += 1;
                hi_r = max(1,hi_r - 1);
                raw[hi_r] -= 1;
            } else if (s[i] == 'D'){
                raw[lo_r] -= 1;
                lo_r = min(n+1,lo_r + 1);
                raw[lo_r] += 1;
                raw[hi_r] += 1;
                hi_r = min(n+1,hi_r + 1);
                raw[hi_r] -= 1;
            } else if (s[i] == 'L'){
                cal[lo_c] -= 1;
                lo_c = max(1,lo_c - 1);
                cal[lo_c] += 1;
                cal[hi_c] += 1;
                hi_c = max(1,hi_c - 1);
                cal[hi_c] -= 1;
            } else{
                cal[lo_c] -= 1;
                lo_c = min(m+1,lo_c + 1);
                cal[lo_c] += 1;
                cal[hi_c] += 1;
                hi_c = min(m+1,hi_c + 1);
                cal[hi_c] -= 1;
            }
        }
        int l,r,u,d;
        l = r = u = d = INT_MAX;
        for (int i=1;i<=n+1;i++){
            if (raw[i] == 1){
                u = i;
            } else if (raw[i] == -1){
                d = i;
            }
            raw[i] += raw[i-1];
        }
        for (int i=1;i<=m+1;i++){
            if (cal[i] == 1){
                l = i;
            } else if (cal[i] == -1){
                r = i;
            }
            cal[i] += cal[i-1];
        }
        int res = (d - u) * (r - l);
        if (res == 0 && k == 0){
            cout << n * m << '\n';
            continue;
        } else if (res == 0 && k > 0){
            cout << 0 << '\n';
            continue;
        }
        string rs = "";
        for (int i=s.length()-1;i>=0;i--){
            if (s[i] == 'U') rs.push_back('D');
            if (s[i] == 'D') rs.push_back('U');
            if (s[i] == 'L') rs.push_back('R');
            if (s[i] == 'R') rs.push_back('L');
        }
        map<pair<int,int>,int> vis;
        int x,y;
        x = 0, y = 0;
        vis[{x,y}] = 1;
        vector<vector<int>> pre(n+2,vector<int>(m+2,0));
        pre[u][l] += 1, pre[u][r] -= 1;
        pre[d][l] -= 1, pre[d][r] += 1;
        for (int i=0;i<rs.length();i++){
            x += f[rs[i]].first;
            y += f[rs[i]].second;
            u += f[rs[i]].second, d += f[rs[i]].second, l += f[rs[i]].first, r += f[rs[i]].first;
            if (vis[{x,y}]) continue;
            vis[{x,y}] = 1;
            pre[u][l] += 1, pre[u][r] -= 1;
            pre[d][l] -= 1, pre[d][r] += 1;
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                pre[i][j] = pre[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
        int cnt = 0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (pre[i][j] == res - k){
                    cnt ++;
                }
            }
        }
        cout << cnt << '\n';
    }
}