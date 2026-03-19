#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int Set[N];
int findx(int x){
    if (Set[x] != x){
        Set[x] = findx(Set[x]);
    }
    return Set[x];
}
void merge(int a,int b){
    Set[max(a,b)] = min(a,b);
}
int main(){
    int n,m;
    int z,x,y;
    cin >> n >> m;
    for (int i=0;i<=n;i++){
        Set[i] = i;
    }
    for (int i=0;i<m;i++){
        cin >> z >> x >> y;
        if (z == 1){
            merge(findx(x),findx(y));
        } else{
            cout << (findx(x)==findx(y)?"Y\n":"N\n");
        }
    }
}