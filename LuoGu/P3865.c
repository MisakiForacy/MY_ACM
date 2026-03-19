#include <stdio.h>
#include <string.h>
#include <math.h>

#define LL long long
#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)
#define N 100010

LL a[N], st[N][20];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        st[i][0] = a[i];
    }
    for (int l=1;l<20;l++){
        for (int i=1;i<=n-(1<<l)+1;i++){
            st[i][l] = max(st[i][l-1],st[i+(1<<l-1)][l-1]);
        }
    }
    while (q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int k = r - l + 1;
        k = (int)log2(k);
        printf("%lld\n",max(st[l][k],st[r-(1<<k)+1][k]));
    }
}