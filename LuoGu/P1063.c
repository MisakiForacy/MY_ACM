#include <stdio.h>
#include <string.h>

#define LL long long
#define min(x,y) (x) < (y) ? (x) : (y)
#define max(x,y) (x) > (y) ? (x) : (y)

int main(){
    int n;
    scanf("%d",&n);
    LL a[205];
    LL dp[205][205];
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i+n] = a[i];
    }
    for (int l=2;l<=n;l++){
        for (int i=1;i<=2*n-l+1;i++){
            int j = i + l - 1;
            for (int k=i;k<j;k++){
                dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
            }
        }
    }
    LL ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans,dp[i][i+n-1]);
    }
    printf("%lld\n",ans);
}