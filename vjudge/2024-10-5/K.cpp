#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 200;
const int P = 2;
vector<vector<int>> mp;
int n,m;
set<LL> st;
LL qpower(LL a,LL k){
    LL res = 1;
    while (k){
        if (k&1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}
int a[N];
void dfs(int idx,int ){

}
int main(){
    cin >> n >> m;
    mp.resize(m+1,vector<int>(n+1));
    set<LL> st;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin >> mp[i][j];
        }
    }
    if (m <= 20){
        // for (int i=1;i<=m;i++){
        //     dfs(1,i,{});
        //     cout << i << '\n';
        // }
        dfs(1,3,{});
        cout << st.size() << '\n';
    } else{

    }
}