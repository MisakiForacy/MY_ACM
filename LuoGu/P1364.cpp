#include <bits/stdc++.h>
using namespace std;
int num[105],w[105];
map<int,set<int>>tree;
queue<pair<int,int>>Q;
int main(){
    int n,n1,n2,len,q,ans,mi = 0x3f3f3f3f;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d%d%d",&w[i],&n1,&n2);
        tree[i].insert(n1);
        tree[i].insert(n2);
        tree[n1].insert(i);
        tree[n2].insert(i);
    }
    for (int i=1;i<=n;i++){
        memset(num,-1,sizeof(num));
        ans = 0;
        Q.push({i,0});
        num[i] = 0;
        while (!Q.empty()){
            q = Q.front().first;
            len = ++Q.front().second;
            Q.pop();
            if (q){
                for (auto &nx:tree[q]){
                    if (num[nx]){
                        Q.push({nx,len});
                        ans += len * w[nx];
                        num[nx] = 0;
                    }
                }
            }
        }
        if (ans < mi){
            mi = ans;
        }
    }
    printf("%d\n",mi);
}