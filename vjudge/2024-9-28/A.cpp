#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=2*n;i+=2){
        printf("%d %d\n%d %d\n",i/2+i%2,i/2+1,i/2+i%2,i/2+2);
    }
    printf("%d %d\n",n,1);
    int kk = k - 2*n;
    for (int i=1;i<=n;i++){

    }
}