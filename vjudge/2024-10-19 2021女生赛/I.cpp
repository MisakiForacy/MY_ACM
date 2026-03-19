#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int dx[] = {0,1,1,1,0,-1,-1,-1};
const int dy[] = {-1,-1,0,1,1,1,0,-1};
int main(){
    int n,m,q;
    string s;
    cin >> n >> m;
    int x,y,v;
    v = 0;
    vector<vector<int>> mp(n+2,vector<int>(m+2,1));
    for (int i=1;i<=n;i++){
        cin >> s;
        for (int j=1;j<=m;j++){
            mp[i][j] = (s[j-1]=='#');
            if (s[j-1] == '*'){
                x = j,y = i;
            }
        }
    }
    cin >> q;
    cin >> s;
    int k = 0;
    for (int i=0;i<q;i++){
        if (s[i]=='U'){
            v ++;
        } else if (s[i]=='D'){
            v = max(--v,0);
        } else if (s[i]=='R'){
            k = (k + 1) % 8;
        } else{
            k = (k + 7) % 8; 
        }
        int ok = 0;
        for (int i=0;i<v;i++){
            if (mp[y+dy[k]][x+dx[k]]){
                ok = 1;
                v = 0;
                break;
            }
            if (k==1 && mp[y-1][x] && mp[y][x+1]){
                ok = 1;
                v = 0;
                break;
            } else if (k==3 && mp[y+1][x] && mp[y][x+1]){
                ok = 1;
                v = 0;
                break;
            } else if (k==5 && mp[y+1][x] && mp[y][x-1]){
                ok = 1;
                v = 0;
                break;
            } else if (k==7 && mp[y-1][x] && mp[y][x-1]){
                ok = 1;
                v = 0;
                break;
            }
            x += dx[k], y += dy[k];
        }
        if (ok){
            cout << "Crash! ";
        }
        cout << y << ' ' << x << '\n';
    }
}