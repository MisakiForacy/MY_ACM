#include <bits/stdc++.h>
#define N (int)(1e6+10)
using namespace std;
int n,step,node;
int var[N];
queue<pair<int,int>>Q;
int main(){
    memset(var,0,sizeof(var));
    cin >> n;
    Q.push({0,1});
    var[1] = 1;
    while(!Q.empty()){
        step = Q.front().first;
        node = Q.front().second;
        if(node == n) break;
        Q.pop();
        if (node+1<=n && !var[node+1]){
            Q.push({step+1,node+1});
            var[node+1] = 1;
        }
        if (node-1>=1 && !var[node-1]){
            Q.push({step+1,node-1});
            var[node-1] = 1;
        }
        if (node * 2 <= n && !var[node * 2]){
            Q.push({step+1,node*2});
            var[node*2] = 1;
        }
    }
    cout << step << endl;
}