#include <bits/stdc++.h>
#define N 50005
using namespace std;
int main(){
    int n,m,st,nu;
    cin >> n >> m;
    if (m<=n){
        cout << n-m << '\n';
    } else{
        int var[N];
        memset(var,0,sizeof(var));
        var[n] = 1;
        queue<pair<int,int>>Q;
        Q.push({n,0});
        while (!Q.empty()){
            st = Q.front().second;
            nu = Q.front().first;
            if (nu==m){
                break;
            }
            Q.pop();
            if (nu-1>0 && !var[nu-1]){
                Q.push({nu-1,st+1});
                var[nu-1] = 1;
            }
            if (nu<m && !var[nu*2]){
                Q.push({nu*2,st+1});
                var[nu*2] = 1;
            }
        }
        cout << st << '\n';
    }
}