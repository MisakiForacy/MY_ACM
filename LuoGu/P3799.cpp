#include <bits/stdc++.h>
using namespace std;
bool check(){
    sort(a,a+4);
    if (a[0]+a[1]==a[2]&&a[2]==a[3]){
        return 1;
    }
    return 0;
}
int dfs(int idx,int k){
    int ans = 0;
    if (!k){
        return check();
    }
    for (int i=0;i<idx;i++){
        ans += 
    }
}