#include <bits/stdc++.h>
using namespace std;
int n,r;
int a[23];
void dfs(int res,int idx){
    if (!res){
        for (int i=0;i<r;i++){
            printf("%3d",a[i]);
        }
        cout << '\n';
        return;
    }
    for (int i=idx;i<n;i++){
        a[r-res] = i + 1;
        dfs(res-1,i+1);
    }
}
int main(){
    cin >> n >> r;
    dfs(r,0);
}