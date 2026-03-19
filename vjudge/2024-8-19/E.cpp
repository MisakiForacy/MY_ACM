#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e6+5;
int Set[N];
void init(int n){
    for (int i=0;i<=n;i++){
        Set[i] = i;
    }
}
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
    while (~scanf("%d%d",&n,&m)){
        if (n==0 && m==0) break;
        init(n);
        int k,fi,x,cnt = 0;
        for (int i=0;i<m;i++){
            scanf("%d%d",&k,&fi);
            for (int i=1;i<k;i++){
                scanf("%d",&x);
                merge(findx(fi),findx(x));
            }
        }
        for (int i=0;i<=n;i++){
            if (findx(i)==0){
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}