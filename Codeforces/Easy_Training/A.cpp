#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,idx;
    char cal;
    scanf("%d",&t);
    while(t --){
        cin >> cal >> idx;
        for(int i=97;i<cal;i++)printf("%c%d\n",i,idx);
        for(int i=cal+1;i<=104;i++)printf("%c%d\n",i,idx);
        for(int i=1;i<idx;i++)printf("%c%d\n",cal,i);
        for(int i=idx+1;i<=8;i++)printf("%c%d\n",cal,i);
    }
    return 0;
}