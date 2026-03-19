#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
ll n,m,mi = inf;
int a[3];
vector<vector<char>>mp;
ll check(int a,int b,int c){
    ll sum = 0;
    for (int i=0;i<a;i++){
        for (int j=0;j<m;j++){
            if (mp[i][j] != 'W') sum ++;
        }
    }
    for (int i=a;i<a+b;i++){
        for (int j=0;j<m;j++){
            if (mp[i][j] != 'B') sum ++;
        }
    }
    for (int i=a+b;i<n;i++){
        for (int j=0;j<m;j++){
            if (mp[i][j] != 'R') sum ++;
        }
    }
    return sum;
}
void dfs(int t,int r){
    if (t==1){
        mi = min(check(a[0],a[1],r),mi);
        return;
    }
    if (t==2&&r==1){
        return;
    }
    for (int i=1;i<r;i++){
        a[3-t] = i;
        dfs(t-1,r-i);
    }
}
int main(){
    string s;
    cin >> n >> m;
    mp.resize(n,vector<char>(m));
    for (int i=0;i<n;i++){
        cin >> s;
        for (int j=0;j<m;j++){
            mp[i][j] = s[j];
        }
    }
    dfs(3,n);
    cout << mi << '\n';
}