#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
const int N = 50005;
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
    int T = 0;
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        T ++;
        if (n==0 && m==0) break;
        init(n);
        int x,y;
        for (int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            merge(findx(x),findx(y));
        }
        set<int>st;
        for (int i=1;i<=n;i++){
            st.insert(findx(i));
        }
        printf("Case %d: %d\n",T,st.size());
    }
}