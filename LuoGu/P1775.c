#include <stdio.h>
#include <string.h>

#define LL long long
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int main(){
    int n;
    scanf("%d",&n);
    LL dp[305][305];
    LL pre[305],a[305];
    LL s = 0;
    memset(dp,0xf,sizeof(dp));
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        dp[i][i] = 0;
        pre[i] = s += a[i];
    }
    for (int len=2;len<=n;len++){
        for (int i=1;i<=n-len+1;i++){
            for (int k=i;k<i+len-1;k++){
                dp[i][i+len-1] = min(dp[i][i+len-1],dp[i][k]+dp[k+1][i+len-1]+pre[i+len-1]-pre[i-1]);
            }
        }
    }
    printf("%lld",dp[1][n]);
}